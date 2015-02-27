﻿//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"

enum Window {
	WIDTH = 512,
	HEIGHT = 512
};

struct Ball{
	float x;
	float y;
	float x_speed;
	float y_speed;

}ball;

//動き
void Ball_Move(){

	ball.x += ball.x_speed;
	ball.y += ball.y_speed;

	if (Window::WIDTH / 2 <= ball.x + 20 && ball.x_speed == 2){
		ball.x_speed = -2;
	}

	if (-Window::WIDTH / 2 >= ball.x - 20 && ball.x_speed == -2){
		ball.x_speed = 2;
	}

	if (Window::HEIGHT / 2 <= ball.y + 20 && ball.y_speed == 2)  {
		ball.y_speed = -2;
	}

	if (-Window::HEIGHT / 2 >= ball.y - 20 && ball.y_speed == -2){
		ball.y_speed = 2;
	}

}

//初期化
void Init(){
	ball.x = -100;
	ball.y = 150;
	ball.x_speed = 2;
	ball.y_speed = 2;
}

int main()
{
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	Init();
	while (env.isOpen()){

		if (env.isPushKey(GLFW_KEY_ESCAPE)) return 0;
	
		Ball_Move();
	
		if (env.isPressKey('G')) ball.y_speed += -1.0;
	
		env.setupDraw(); // 描画準備

		drawFillCircle(ball.x , ball.y, 15, 15, 100,Color(0,1,1));
		
		
		env.update();
	}
}