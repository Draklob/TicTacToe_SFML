#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <memory>
#include <stack>

#include "State.h"

typedef std::unique_ptr<State> StateRef;
typedef int Lucas;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void AddState( StateRef newState, bool isReplacing = true);
	void RemoveState();

	void ProcessStateChanges();

	StateRef &GetActiveState();

private:
	std::stack<StateRef> _states;
	StateRef _newState;

	bool _isRemoving;
	bool _isAdding;
	bool _isReplacing;
};

#endif // STATE_MACHINE_H