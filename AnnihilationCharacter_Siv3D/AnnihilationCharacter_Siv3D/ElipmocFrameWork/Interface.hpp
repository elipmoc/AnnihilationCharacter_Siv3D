#pragma once

namespace elipmocframework {
	//削除するかどうかのフラグを持つinterface
	class has_delete_flag {
	protected:
		bool delete_flag = false;
	public:
		bool IsEnableDelete()const noexcept { return delete_flag; }
	};

}