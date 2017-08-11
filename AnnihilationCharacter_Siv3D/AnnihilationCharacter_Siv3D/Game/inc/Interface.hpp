#pragma once

namespace game {
	//íœ‚·‚é‚©‚Ç‚¤‚©‚Ìƒtƒ‰ƒO‚ğ‚Âinterface
	class has_delete_flag {
	protected:
		bool delete_flag = false;
	public:
		bool IsEnableDelete()const noexcept { return delete_flag; }
	};

}