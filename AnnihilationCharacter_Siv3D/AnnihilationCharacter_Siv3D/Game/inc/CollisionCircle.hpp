#pragma once
#include <functional>
#include "Interface.hpp"

namespace game {

	//�R���W�������ʔԍ�
	enum class CollisionID {
		EnemyID,
		EnemyBulletID,
		PlayerID,
		BarrierID,
		ItemID
	};

	class CollisionCircle;
	struct CollisionData:public elipmocframework::has_delete_flag {
		const CollisionCircle& m_collision;
		CollisionData(const CollisionCircle& collision) noexcept:m_collision(collision) {

		}
		void EnableDelete() noexcept{ delete_flag = true; }
	private:

	};

	//�~�̂����蔻��
	class CollisionCircle {

		CollisionData& m_colliData;

		const siv::Vec2& bind_pos;
		//���a
		double m_r;
		//���炷���W
		siv::Vec2 m_offsetPos;

		//�Փ˃L���[
		mutable siv::Array<CollisionID> m_colliQueue;

		CollisionID m_collisionID;
		//�Փ˂����Ƃ��ɌĂ΂��֐�
		const std::function<void(CollisionID)> m_hitFunc;
		//CollisionControl�ɓo�^����
		void RegisterCollision();
	public:
		CollisionID GetCollisionID()const noexcept{ return m_collisionID; }
		void SetCollisionID(const CollisionID collisionID)noexcept{ m_collisionID=collisionID; }

		siv::Vec2 GetBindPos()const noexcept{ return bind_pos; }

		siv::Vec2 GetPos()const noexcept{ return bind_pos+m_offsetPos; }

		siv::Vec2 GetOffsetPos()const noexcept{ return m_offsetPos; }
		void SetOffsetPos(const siv::Vec2& offsetPos) noexcept{ m_offsetPos=offsetPos; }

		double GetR()const noexcept{ return m_r; }
		void SetR(const double r) noexcept{ m_r = r; }


		//�����蔻��v�Z
		void HitCheck(const CollisionCircle& cc)const {
			const auto&& temp= ((bind_pos + m_offsetPos) - (cc.bind_pos + cc.m_offsetPos));
			if ((temp.x*temp.x + temp.y*temp.y) <= (m_r + cc.m_r)*(m_r + cc.m_r)) {
				m_colliQueue.push_back(cc.m_collisionID);
				cc.m_colliQueue.push_back(m_collisionID);
			}
		}


		//�Փˏ��������s
		void DoColliQueue() {
			for (const auto& id : m_colliQueue) {
				m_hitFunc(id);
			}
			m_colliQueue.clear();
		}

		//���W�Ɗ֐����o�C���h����
		template<class F>
		CollisionCircle(const siv::Vec2& pos,F func)
			:bind_pos(pos),m_hitFunc(func),m_colliData(*(new CollisionData(*this))){
			RegisterCollision();
		}

		//�f�o�b�O�`��
		void DebugDraw() const{
			siv::Circle(GetPos(), m_r).draw({255,0,0,150});
		}

		//�f�X�g���N�^
		~CollisionCircle() noexcept{
			m_colliData.EnableDelete();
		}

	};



}