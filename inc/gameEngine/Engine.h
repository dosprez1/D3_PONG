/*
 * Engine.h
 *
 *  Created on: 7 mei 2017
 *      Author: Acer
 */

#ifndef INC_GAMEENGINE_ENGINE_H_
#define INC_GAMEENGINE_ENGINE_H_

#include <Vector.h>
#include <gameEngine/Ball.h>

class GameObject;
namespace GameEngine {

class Engine {
public:
								Engine();
	virtual 					~Engine();

public:
	virtual void				moveBall();
	Ball						*getBall();


public:
	virtual void				addObject(GameObject *object);
	virtual void				emtpyContainer();

private:
	Ball						m_ball;
	Vector<GameObject *>		m_objectContainer;

	void						getTransformFactors(Coordinate &speed, Vector<int32_t> &transformList);
	int32_t						getTransformFactor(GameObject* object,
										Coordinate& ballSpeed);

	void						deleteAllObjects();
	bool						existsSaveTransform(int selected, Vector<int32_t> *transformList, Coordinate *ballSpeed);
	Coordinate 					getReativeBall(GameObject* nearestObject, Coordinate ballPos);
};

} /* namespace GameEngine */

#endif /* INC_GAMEENGINE_ENGINE_H_ */
