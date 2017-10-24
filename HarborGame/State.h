#pragma once
class State
{
public:
	static State & Instance();

	bool GetQuitState() const;
	void SetQuitState(bool newState);

private:
	State(): quit(false) { };
	bool quit;
};
