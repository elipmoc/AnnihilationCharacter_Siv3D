#pragma once
#include <type_traits>
#include "pack_traits_original.hpp"

namespace elipmocframework {

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


	//全てのArgsが被っていなければtrue
	template<class...> struct variadic_is_distinct : std::true_type { };
	template<class B1, class B2,class... Bn>
	struct variadic_is_distinct<B1,B2,Bn...>
		: std::conditional_t<!variadic_is_sames_v<B1,B2,Bn...>, variadic_is_distinct<B2,Bn...>, std::false_type> {};

	template<class ...Args>
	constexpr bool variadic_is_distinct_v = variadic_is_distinct<Args...>::value;

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
}