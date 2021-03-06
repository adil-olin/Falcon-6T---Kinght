#pragma once
#ifndef structure_hpp
#define structure_hpp 

#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
#include<bits/stdc++.h>
#include "defs.hpp"
using namespace std;

//this delegate variable will store every logic and draw function which will be in the while loop of main.cpp
struct Delegate
{
	void (*logic)(void);
	void (*draw)(void);
};


//storing textures
struct Texture 
{
	char name[MAX_NAME_LENGTH];
	SDL_Texture *texture;
	Texture *next;
};

//for highscores
struct Highscore
{
	int recent;
	char name[MAX_SCORE_NAME_LENGTH];
	int score;
};


struct Highscores
{
	Highscore highscore[NUM_HIGHSCORES];
}highscores;


struct App
{
	SDL_Renderer *renderer;
	SDL_Window *window;
	Delegate delegate;
	int keyboard[MAX_KEYBOARD_KEYS];
	int mouse[350];
	vector<Texture>AllTexture;
	char inputText[MAX_LINE_LENGTH];
}app;


//store player,enemy,boss and bullets
struct Entity
{
	float x;
	float y;
    int health,reload,w,h,life,energy;
	float dx,dy;
	int side;
	SDL_Texture *texture;

	bool operator == (const Entity &p)
	{
		return (p.x==x && p.y==y && p.dx==dx && p.dy==dy && p.health==health && p.reload==reload && p.w==w && p.h==h && p.side==side &&p.texture==texture);
	}
	bool operator !=(const Entity &p)
	{
		return !(p.x==x && p.y==y && p.dx==dx && p.dy==dy && p.health==health && p.reload==reload && p.w==w && p.h==h && p.side==side && p.texture==texture);
	}

} player; 

struct Explosion 
{
	float x;
	float y;
	float dx;
	float dy;
	int r, g, b, a;
};

struct Debris 
{
	float x;
	float y;
	float dx;
	float dy;
	SDL_Rect rect;
	SDL_Texture *texture;
	int life;
};

struct Star
{
	int x;
	int y;
	int speed;
} stars[MAX_STARS];

struct Stage
{
	//bullet will contain all type of bullet from enemy or ally
	//Fighter will do same for enemy and the player. Here player will act as reference

	vector<Entity> Bullet,Fighter,pointpod;
	vector<Explosion> explosion;
	vector<Debris> debris;
	int score;

} stage;

bool isplayernull = false,isbossnull=true, isstarted;

Entity Boss,ultEnergy;

int enemyspawntimer,stageResetTimer,backgroundY,esc,level,boss_reload,boss_timer,continue_timer;
int MouseX, MouseY;//mouse's position

SDL_Rect r;
SDL_Texture *alienBulletTexture;
SDL_Texture *playerTexture;
SDL_Texture *bulletTexture;
SDL_Texture *enemyTexture;
SDL_Texture *explosionTexture;
SDL_Texture *background;
SDL_Texture *fontTexture;
SDL_Texture *lifepod;
SDL_Texture *healthbar;
SDL_Texture *healthstat;
SDL_Texture *Life;
SDL_Texture *BLife;
SDL_Texture *logo;
SDL_Texture *home;
SDL_Texture *load0;
SDL_Texture *load1;
SDL_Texture *load2;
SDL_Texture *title0;
SDL_Texture *title1;
SDL_Texture *title2;
SDL_Texture *point;
SDL_Texture *instruction;
SDL_Texture *crdt;
SDL_Texture *one;
SDL_Texture *two;
SDL_Texture *three;
SDL_Texture *Ult;
SDL_Texture *engr;
SDL_Texture *ultpower;
Mix_Music *homemus;
Mix_Chunk *bulletmus;
Mix_Chunk *ebullet;
Mix_Chunk *podsound;
Mix_Chunk *lifemus;
Mix_Chunk *ultmus;
Mix_Chunk *bosspowmus;
Mix_Chunk *boss;
Mix_Chunk *bossdeath;
Mix_Chunk *Cursor_sound;
Mix_Chunk *Player_death;
Mix_Chunk *Ult_sound;
Mix_Chunk *menubar;



int highscore = 0;

#endif
