#pragma once
#include <type_traits>

namespace elipmocframework {
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
	constexpr bool is_sames_v = is_sames<Target,Tails...>::value;
}