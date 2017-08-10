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
	template<class...>
	struct is_sames;

	template<class Head,class Head2,class ...Tails >
	struct is_sames<Head, Head2, Tails...>
		:
		std::conditional_t<
			std::is_same<Head,Head2>::value,
				std::true_type,
				std::conditional_t<is_sames<Head,Tails...>::value,std::true_type,std::false_type>
		>
	{};

	template<class Head>
	struct is_sames<Head>:std::false_type
	{};

	template<class Head,class Head2,class ...Tails>
	constexpr bool is_sames_v = is_sames<Head,Head2,Tails...>::value;
}