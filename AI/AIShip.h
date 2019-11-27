#pragma once
#include "../General/Ship.h"
#include "../General/Sprite.h"

class AIShip: public Ship{
    public:
		AIShip();
		AIShip(SDL_Rect dbox,SDL_Texture* aTex,bool ally);
		bool followPath(vector<Sprite *>* osSprite);
		void setGoal(int newGoal);
		int getGoal();
		bool getPathComplete();
		void setDestination(pair<int,int> newDestination);
		pair<int,int> getDestination();
		void setPath(queue<pair<int,int>>* thePath);
		Projectile attackShip(pair<int,int> otherShip, SDL_Texture* laser);
		void resetVariables();
		bool isPathSet();
		bool isFreeForm(); //can autonomously switch states
		Uint32 getTime();
		void switchFreeForm();
		void setTime(Uint32 startTime);
    private:
		void calculateNewAngle(pair<int,int> destination);
		void collision_check(int x, int y, vector<Sprite *>* osSprite);
		bool rotateToAngle();

		int deterXAxisMovement(int cur_x, int x_coord, int* xmov, bool* xai);

		int moveRight(int cur_x, int x_coord, bool* xai);
		int moveLeft(int cur_x, int x_coord, bool* xai);

		int deterYAxisMovement(int cur_y, int y_coord, int * ymov, bool*  yai);
		int moveUp(int cur_y, int y_coord, bool*  yai);
		int moveDown(int cur_y, int y_coord, bool*  yai);

		bool colRes(vector<Sprite *>* osSprite, int cur_x, int cur_y, int xmov, int ymov, bool xai, bool yai);

		bool pathComplete;
		pair<int,int> destination;
        std::queue<pair<int,int>>* path;
        int curGoal;//'modes' of ai: follow, defend, attack, flee = {0,1,2,3} for now
        bool pathset;
		bool freeForm;
		Uint32 timeActivated;
};
