#pragma once

namespace game {
	//�폜���邩�ǂ����̃t���O������interface
	class has_delete_flag {
	protected:
		bool delete_flag = false;
	public:
		bool IsEnableDelete()const noexcept { return delete_flag; }
	};

}