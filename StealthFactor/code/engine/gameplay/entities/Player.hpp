#pragma once

#include <engine/gameplay/entities/Character.hpp>
#include "engine/input/InputComponent.h"

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Player : public Character
			{
			public:
				Player();

				void Update();

				bool hasJustMoved() const;

			private:
				bool justMoved{ false };
				InputComponent* inputComponent;
			};
		}
	}
}
