#pragma once

namespace elipmocframework {

	template < class ...Types >
	struct type_pack {
		template < template<class...>class Expr >
		using expr = Expr<Types...>;
	};

	//Argsから任意の数をとりだしてtype_packに後ろから詰める
	template<size_t, class , class...>
	struct type_pack_push_back_n {};

	template<size_t N,class ...PackArgs,class Head,class ...Tails>
	struct type_pack_push_back_n<N,type_pack<PackArgs...>,Head,Tails...>
		:type_pack_push_back_n<N - 1, type_pack<PackArgs..., Head>,Tails...>
	{};

	template<class ...PackArgs>
	struct type_pack_push_back_n<0,type_pack<PackArgs...> >
	{
		using resultPack = type_pack<PackArgs...>;
		using remainingPack = type_pack<>;
	};

	template<class ...PackArgs,class Head,class... Tails>
	struct type_pack_push_back_n<0, type_pack<PackArgs...>,Head,Tails... >
	{
		using resultPack = type_pack<PackArgs...>;
		using remainingPack = type_pack<Head,Tails...>;
	};

	//二つのpackを合体させる(クランベリーコピペした)
	template < class... >
	struct pack_cat;

	template < template < class... > class Pack, class... Left, class... Right >
	struct pack_cat<Pack<Left...>, Pack<Right...>> {
		using type = Pack<Left..., Right...>;
	};

	template < class Pack1st, class Pack2nd, class... PackTail >
	struct pack_cat<Pack1st, Pack2nd, PackTail...>
		: pack_cat<typename pack_cat<Pack1st, Pack2nd>::type, PackTail...>
	{};

	template < class... Pack >
	using pack_cat_t = typename pack_cat<Pack...>::type;


	//Argsを複数のtype_packに分割してまとめる
	template<size_t,class,class>
	struct pack_split{};

	template<size_t N,class ...PackArgs, class ...PackArgs2>
	struct pack_split<N, type_pack<PackArgs...>, type_pack<PackArgs2...> >
		:pack_split<
			N, 
			pack_cat_t<
				type_pack<PackArgs...>,
				type_pack<typename type_pack_push_back_n<N,type_pack<>, PackArgs2...>::resultPack>
			>,
			typename type_pack_push_back_n<N, type_pack<>, PackArgs2...>::remainingPack
		>
	{};

	template<size_t N, class ...PackArgs>
	struct pack_split<N, type_pack<PackArgs...>, type_pack<> >
	{
		using type = type_pack<PackArgs...>;
	};
	
	template<size_t N,class ...Args>
	using pack_split_t =typename pack_split<N, type_pack<>, type_pack<Args...>>::type;

	//packの型を入れ替える（クランベリーよりパクった）
	template < class >
	struct repack;

	template<template<typename...> class T, typename... Args>
	struct repack< T<Args...> > {

		template < template<class...> class U >
		using type = U<Args...>;
	};

	template < typename From, template < class ... > class To >
	using repack_t = typename repack<From>:: template type<To>;

	//ネストされたpackの型を変更する
	template<class>
	struct nest_repack;

	template<template<class...>class Pack,class ...NestPacks>
	struct nest_repack<Pack<NestPacks...>>{
		template<template<class...>class ToPack>
		using type = Pack<repack_t<NestPacks,ToPack>...>;
	};

	template < class From, template < class ... > class To >
	using nest_repack_t = typename nest_repack<From>:: template type<To>;

}