
#pragma once

#include "entity.h"
#include "script/weapon.h"

class ActorController;

class Actor : public Entity
{

public:

	enum Faction { GOOD, BAD, NEUTRAL };
	Faction faction;

	// offset de ángulo y dirección de movimiento
	cml::vector2f rotation_offset, move_direction;

	// última vez que se aplicó daño
	int last_pain;

	// atacó en el ultimo frame?
	bool attack;

	// PWR: aumenta daño armas
	// DEF: reduccion daño armas
	// PSI: daño psi, energia magica
	// DKM: daño dkm, energia magica
	// AGI: critico, velocidad de movimiento
	struct { float pwr, def, psi, dkm, agi; } stats;

	// vida
	struct { int current, total; } hp;

	// efectos
	struct { uint32_t duration, last_pain; } fallout;
	struct { uint32_t slow, freeze, confuse; } effect;

	Weapon wep; // PUESTO AQUI PARA DEPURAR
	// EN UN FUTURO; PUNTERO A WEAPON Y EN PLAYER, PLAYERWEAPON

	void ApplyLinearVelocity()
	{
		body->SetLinearVelocity(b2Vec2(move_direction[0],move_direction[1]));
	}

};
