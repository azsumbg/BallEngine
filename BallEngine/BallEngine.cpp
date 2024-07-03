#include "pch.h"
#include "BallEngine.h"

class BALL :public dll::OBJECT
{
	public:

		BALL(types atype, float ax, float ay) :OBJECT(atype, ax, ay)
		{
			switch (color)
			{
			case colors::blue:
				speed = 0.8f;
				break;

			case colors::green:
				speed = 0.7f;
				break;

			case colors::purple:
				speed = 0.6f;
				break;

			case colors::red:
				speed = 0.5f;
				break;

			case colors::yellow:
				speed = 0.4f;
				break;
			}
		}

		void Release() override
		{
			delete this;
		}
		void Move(float _speed) override
		{
			float current_speed = speed * _speed;

			switch (dir)
			{
			case dirs::up_left:
				if (x - current_speed > 0 && slope * (x - current_speed) + intercept > 50.0f)
				{
					x -= current_speed;
					y = slope * x + intercept;
					SetEdges();
					break;
				}
				else 
				{
					if (x - current_speed <= 0)
					{
						if (slope * (x - current_speed) + intercept <= 50.0f)
						{
							dir = dirs::down_right;
							SetMoveVector(x, y, (float)(ex + rand() % 50), scr_height - 100.0f);
							break;
						}
						else
						{
							int choice = rand() % 3;
							if (choice == 2)
							{
								dir = dirs::up_right;
								SetMoveVector(x, y, (float)(ex + rand() % 50), 50.0f);
								break;
							}
							else if(choice == 0)
							{
								dir = dirs::down_right;
								SetMoveVector(x, y, (float)(ex + rand() % 50), scr_height - 100.0f);
								break;
							}
							else
							{
								dir = dirs::right;
								break;
							}
						}
					}
					else
					{
						switch (rand() % 3)
						{
						case 0:
							dir = dirs::down_right;
							SetMoveVector(x, y, (float)(x + rand() % 20), scr_height - 100.0f);
							break;

						case 1:
							dir = dirs::down_left;
							SetMoveVector(x, y, (float)(x - rand() % 20), scr_height - 100.0f);
							break;

						case 2:
							dir = dirs::down;
							vert_move = true;
							break;
						}
					}
				}
				break;

			case dirs::up_right:
				if (x + current_speed + GetWidth() < scr_width && slope * (x + current_speed) + intercept > 50.0f)
				{
					x += current_speed;
					y = slope * x + intercept;
					SetEdges();
					break;
				}
				else
				{
					if (x + GetWidth() + current_speed >= scr_width)
					{
						if (slope * (x - current_speed) + intercept <= 50.0f)
						{
							dir = dirs::down_left;
							SetMoveVector(x, y, 0, scr_height - 100.0f);
							break;
						}
						else
						{
							int choice = rand() % 3;
							if (choice == 2)
							{
								dir = dirs::down_right;
								SetMoveVector(x, y, (float)(ex + rand() % 50), scr_height - 100.0f);
								break;
							}
							else if (choice == 0)
							{
								dir = dirs::down_left;
								SetMoveVector(x, y, 0, scr_height - 100.0f);
								break;
							}
							else
							{
								dir = dirs::left;
								break;
							}
						}
					}
					else
					{
						switch (rand() % 3)
						{
						case 0:
							dir = dirs::down_right;
							SetMoveVector(x, y, (float)(x + rand() % 50), scr_height - 100.0f);
							break;

						case 1:
							dir = dirs::down_left;
							SetMoveVector(x, y, (float)(x - rand() % 50), scr_height - 100.0f);
							break;

						case 2:
							dir = dirs::down;
							vert_move = true;
							break;
						}
					}
				}
				break;

			case dirs::down_left:
				if (x - current_speed > 0 
					&& slope * (x - current_speed) + intercept + GetHeight() < scr_height - 100.0f)
				{
					x -= current_speed;
					y = slope * x + intercept;
					SetEdges();
					break;
				}
				else
				{
					if (x - current_speed <= 0)
					{
						if (slope * (x - current_speed) + intercept + GetHeight() >= scr_height - 100.0f)
						{
							dir = dirs::up_right;
							SetMoveVector(x, y, (float)(ex + rand() % 50), 50.0f);
							break;
						}
						else
						{
							int choice = rand() % 3;
							if (choice == 2)
							{
								dir = dirs::up_right;
								SetMoveVector(x, y, (float)(ex + rand() % 50), 50.0f);
								break;
							}
							else if (choice == 0)
							{
								dir = dirs::up_left;
								SetMoveVector(x, y, (float)(ex - rand() % 50), 50.0f);
								break;
							}
							else
							{
								dir = dirs::right;
								break;
							}
						}
					}
					else
					{
						switch (rand() % 3)
						{
						case 0:
							dir = dirs::up_right;
							SetMoveVector(x, y, (float)(ex + rand() % 50), 50.0f);
							break;

						case 1:
							dir = dirs::up_left;
							SetMoveVector(x, y, (float)(x - rand() % 50), 50.0f);
							break;

						case 2:
							dir = dirs::up;
							vert_move = true;
							break;
						}
					}
				}
				break;

			case dirs::down_right:
				if (x + GetWidth() + current_speed < scr_width 
					&& slope * (x + current_speed) + intercept + GetHeight () < scr_height - 100.0f)
				{
					x += current_speed;
					y = slope * x + intercept;
					SetEdges();
					break;
				}
				else
				{
					if (x + GetWidth() + current_speed >= scr_width)
					{
						if (slope * (x - current_speed) + intercept + GetHeight() >= scr_height - 100.0f)
						{
							dir = dirs::up_left;
							SetMoveVector(x, y, 0, 50.0f);
							break;
						}
						else
						{
							int choice = rand() % 3;
							if (choice == 2)
							{
								dir = dirs::up_right;
								SetMoveVector(x, y, (float)(ex + rand() % 50), 50.0f);
								break;
							}
							else if (choice == 0)
							{
								dir = dirs::up_left;
								SetMoveVector(x, y, 0, 50.0f);
								break;
							}
							else
							{
								dir = dirs::right;
								break;
							}
						}
					}
					else
					{
						switch (rand() % 3)
						{
						case 0:
							dir = dirs::up_right;
							SetMoveVector(x, y, (float)(ex + rand() % 50), 50.0f);
							break;

						case 1:
							dir = dirs::up_left;
							SetMoveVector(x, y, (float)(x - rand() % 50), 50.0f);
							break;

						case 2:
							dir = dirs::up;
							vert_move = true;
							break;
						}
					}
				}
				break;

			case dirs::up:
				if (y - current_speed > 50.0f)
				{
					y -= current_speed;
					SetEdges();
					break;
				}
				else
				{
					switch (rand() % 3)
					{
					case 0:
						dir = dirs::down_left;
						SetMoveVector(x, y, 0, scr_height - 100.0f);
						break;

					case 1:
						dir = dirs::down_right;
						SetMoveVector(x, y, scr_width, scr_height - 100.0f);
						break;

					case 2:
						dir = dirs::down;
						vert_move = true;
						break;
					}
				}
				break;

			case dirs::down:
				if (y + GetHeight() + current_speed < scr_height - 100.0f)
				{
					y += current_speed;
					SetEdges();
					break;
				}
				else
				{
					switch (rand() % 3)
					{
					case 0:
						dir = dirs::up_left;
						SetMoveVector(x, y, 0, 50.0f);
						break;

					case 1:
						dir = dirs::up_right;
						SetMoveVector(x, y, scr_width, 50.0f);
						break;

					case 2:
						dir = dirs::up;
						vert_move = true;
						break;
					}
				}
				break;

			case dirs::right:
				if (ex + current_speed < scr_width)
				{
					x += current_speed;
					SetEdges();
					break;
				}
				else
				{
					switch (rand() % 3)
					{
					case 0:
						dir = dirs::up_left;
						SetMoveVector(x, y, 0, 50.0f);
						break;

					case 1:
						dir = dirs::down_left;
						SetMoveVector(x, y, 0, scr_height - 100.0f);
						break;

					case 2:
						dir = dirs::left;
						break;
					}
				}
				break;

			case dirs::left:
				if (x - current_speed > 0)
				{
					x -= current_speed;
					SetEdges();
					break;
				}
				else
				{
					switch (rand() % 3)
					{
					case 0:
						dir = dirs::up_right;
						SetMoveVector(x, y, scr_width, 50.0f);
						break;

					case 1:
						dir = dirs::up_left;
						SetMoveVector(x, y,scr_width, scr_height - 100.0f);
						break;

					case 2:
						dir = dirs::right;
						break;
					}
				}
				break;
			}
		}
		int Transform(sizes to_what) override
		{
			switch (to_what)
			{
			case sizes::middle:
				if (size == sizes::big)
				{
					size = to_what;
					return DLL_OK;
				}
				else return DLL_ERR;
				break;

			case sizes::small_ball:
				if (size == sizes::middle)
				{
					size = to_what;
					return DLL_OK;
				}
				else return DLL_ERR;
				break;
			}
			return DLL_NaN;
		}
		int GetFrame() override
		{
			return DLL_NaN;
		}
};

class CATAPULT :public dll::OBJECT
{
public:

	CATAPULT(float ax, float ay) :OBJECT(types::catapult, ax, ay)
	{
		speed = 5.0f;
	}

	void Release() override
	{
		delete this;
	}
	void Move(float _speed) override
	{
		float myspeed = speed * _speed;
		switch (dir)
		{
		case dirs::left:
			if (x - myspeed >= 0)
			{
				x -= myspeed;
				SetEdges();
				break;
			}
			break;

		case dirs::right:
			if (x + myspeed <= scr_width)
			{
				x += myspeed;
				SetEdges();
				break;
			}
			break;
		}

	}
	int Transform(sizes to_what) override
	{
		return DLL_NaN;
	}
	int GetFrame() override
	{
		frame_delay--;
		if (frame_delay < 0)
		{
			frame_delay = 10;
			current_frame++;
			if (current_frame > 3)current_frame = 0;
		}
		return current_frame;
	}
};

class AXE :public dll::OBJECT
{
public:

	AXE(float start_x, float start_y, float e_x, float e_y) :OBJECT(types::axe, start_x, start_y)
	{
		SetMoveVector(start_x, start_y, e_x, e_y);
		speed = 5.0f;
		if (e_x > x)dir = dirs::up_right;
		else if (e_x < x)dir = dirs::up_left;
		else dir = dirs::up;
	}

	void Release() override
	{
		delete this;
	}
	void Move(float _speed) override
	{
		if (vert_move)
		{
			y -= speed;
			SetEdges();
			return;
		}

		switch (dir)
		{
		case dirs::up_left:
			x -= speed;
			y = slope * x + intercept;
			SetEdges();
			break;

		case dirs::up_right:
			x += speed;
			y = slope * x + intercept;
			SetEdges();
			break;
		}

	}
	int Transform(sizes to_what) override
	{
		return DLL_NaN;
	}
	int GetFrame() override
	{
		return DLL_NaN;
	}
};

dll::Object dll::Factory(types what, float s_x, float s_y)
{
	Object ret = nullptr;

	switch (what)
	{
	case types::egg:
		ret = new BALL(what, s_x, s_y);
		break;

	case types::ball:
		ret = new BALL(what, s_x, s_y);
		break;

	case types::catapult:
		ret = new CATAPULT(s_x, s_y);
		break;
	}
	return ret;
}
dll::Object dll::AxeFactory(float s_x, float s_y, float e_x, float e_y)
{
	Object ret = nullptr;
	ret = new AXE(s_x, s_y, e_x, e_y);
	return ret;
}