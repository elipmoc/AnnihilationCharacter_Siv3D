#pragma once
#include <type_traits>

namespace elipmocframework {

	/*template < bool B >
	using bool_constant = std::integral_constant<bool, B>;

	template < typename Head, typename ...Tail >
	struct conj_impl : bool_constant<Head::value && conj_impl<Tail...>::value> {};

	template < typename B >
	struct conj_impl<B> : bool_constant<B::value> {};

	template < typename ...B >
	struct conjunction : conj_impl<B...> {};

	template < typename ...B >
	constexpr bool conjunction_v = conjunction<B...>::value;*/

	//c++17で追加された関数 conjunction
	template<class...> struct conjunction : std::true_type { };
	template<class B1> struct conjunction<B1> : B1 { };
	template<class B1, class... Bn>
	struct conjunction<B1, Bn...>
		: std::conditional_t<bool(B1::value), conjunction<Bn...>, B1> {};

	//c++17で追加された関数　disjunction
	template<class...> struct disjunction : std::false_type { };
	template<class B1> struct disjunction<B1> : B1 { };
	template<class B1, class... Bn>
	struct disjunction<B1, Bn...>
		: std::conditional_t<bool(B1::value), B1, disjunction<Bn...>> { };

	//Argsの全てががTargetを継承しているオブジェクトであるか判定する
	template<class Target,class ...Args>
	constexpr bool variadic_is_all_base_of_v = conjunction<std::is_base_of<Target,Args>...>::value;

	//Argsのうち一つでもTargetと一致しているならtrue
	template<class Target, class ...Args>
	constexpr bool variadic_is_sames_v = disjunction<std::is_same<Target, Args>...>::value;

	//templateで指定した型の中で
	//一番大きいサイズの奴が返るやーつ
	template<class...>
	struct type_max_size;

	template<size_t size>
	using size_t_constant = std::integral_constant<size_t, size>;

	template<class T>
	struct type_max_size <T>
		:size_t_constant<sizeof(T)>
	{};

	template<class...Types>
	constexpr size_t type_max_size_v = type_max_size<Types...>::value;

	template<class Head, class... Tails>
	struct type_max_size<Head, Tails...>
		:size_t_constant<(sizeof(Head) > type_max_size_v<Tails...>) ? sizeof(Head) : type_max_size_v<Tails...>>
	{};
	
/*
	//複数の型のうち一つでもマッチすればture
	//<比べる対象の型,比べられる型...>
	template<class...>
	struct is_sames;

	template<class Target,class Head,class ...Tails >
	struct is_sames<Target, Head, Tails...>
		:
		std::conditional_t<
			std::is_same<Target,Head>::value,
				std::true_type,
				std::conditional_t<is_sames<Target,Tails...>::value,std::true_type,std::false_type>
		>
	{};

	template<class Target>
	struct is_sames<Target>:std::false_type
	{};

	template<class Target,class...Tails>
	constexpr bool is_sames_v = is_sames<Target,Tails...>::value;*/
}