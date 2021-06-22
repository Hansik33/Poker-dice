#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <experimental/filesystem>
#include <Windows.h>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <time.h>

using namespace std;
using namespace sf;

class Game
{
public:

	RenderWindow window;

	Event event;

	Font font_default;

	const unsigned int WINDOW_X_SIZE = 840;
	const unsigned int WINDOW_Y_SIZE = 650;

	/// GAME PROCESS ///

	void configure_process();
	void process();

	void random_and_set();

	void animation_slow();
	void animation_normal();
	void animation_speed();

	void first_throw();

	void check_value();

	void set_hover(int index);
	void set_back(int index);
	void set_chosen(int index);
	void set_chosen_hover(int index);

	void check_result();

	void pair();
	void two_couples();
	void threesome();
	void small_straight();
	void big_straight();
	void full();
	void four_mesh();
	void poker();

	void pair_enemy();
	void two_couples_enemy();
	void threesome_enemy();
	void small_straight_enemy();
	void big_straight_enemy();
	void full_enemy();
	void four_mesh_enemy();
	void poker_enemy();

	void second_throw_only_enemy();
	void random_and_set_only_enemy();
	void animation_only_enemy_slow();
	void animation_only_enemy_normal();
	void animation_only_enemy_speed();

	void second_throw();
	void random_and_set_only_player();
	void animation_second_throw_slow();
	void animation_second_throw_normal();
	void animation_second_throw_speed();

	void reset();

	void summary();

	void play_again();

	int number[5];
	int number_enemy[5];

	int values[5];
	int values_enemy[5];

	int result[6];
    int result_enemy[6]; 

	int score = 0, score_enemy = 0;

	Texture texture_background, texture_cursor2, texture_throw, texture_rectangle;

	Texture texture_dice[6];

	Texture texture_dice_hover[6];

	Texture texture_dice_chosen[6];

	Texture texture_dice_chosen_hover[6];

	Sprite background, cursor2, sprite_throw, rectangle_status, rectangle_result_enemy, rectangle_result;

	Sprite dice[5];

	Sprite dice_enemy[5];

	Text text_status, text_result_enemy, text_result, text_end;

	SoundBuffer sound_buffer_grab, sound_buffer_throw, sound_buffer_shuffle;
	Sound sound_grab, sound_throw, sound_shuffle;

	Clock clock04, clock05, clock06;

	const float RECTANGLE_X_ORIGIN = 560;
	const float RECTANGLE_Y_ORIGIN = 210;
	const float RECTANGLE_X_POSITION = 950;
	const float RECTANGLE_Y_POSITION = 540;

	const float TEXT_STATUS_X_POSITION = 665;
	const float TEXT_STATUS_Y_POSITION = 500;

	const float TEXT_RESULT_ENEMY_X_POSITION = 505;
	const float TEXT_RESULT_ENEMY_Y_POSITION = 25;

	const float TEXT_RESULT_X_POSITION = 600;
	const float TEXT_RESULT_Y_POSITION = 1010;

	const float DICE_X_ORIGIN = 100;
	const float DICE_Y_ORIGIN = 100;

	const float CURSOR2_X_ORIGIN = 33;
	const float CURSOR2_Y_ORIGIN = 36;

	float DICE_X_POSITION = 275;
	float DICE_Y_POSITION = 850;

	const float THROW_X_ORIGIN = 420;
	const float THROW_Y_ORIGIN = 320;
	const float THROW_X_POSITION = 1800;
	const float THROW_Y_POSITION = 500;

	bool isOnThrow = false;
	bool isAfterFirstThrow = false;

	bool isDiceChosen[5];

	bool isPair[6];
	bool isPair_enemy[6];

	bool isThreesome;
	bool isPair_Threesome;

	bool isThreesome_enemy;
	bool isPair_Threesome_enemy;

	bool isAnyChosen = false;

	bool doThrowAgain[5];

	bool doCheckScore = false;

	bool isEnd = false;

	/// MENU ///

	void configure_menu();
	void menu();

	Texture texture_button_start, texture_button_start_selected, texture_button_info, texture_button_info_selected, texture_button_exit, texture_button_exit_selected, texture_cursor;

	Sprite button_start, button_start_selected, button_info, button_info_selected, button_exit, button_exit_selected, cursor;

	SoundBuffer sound_buffer_sound_button, sound_buffer_clicked_sound, empty;

	Sound sound_sound_button, sound_clicked_sound;

	Vector2i mousePos;

	Clock clock01, clock02, clock03;

	int which_chosen = 0;

	const float BUTTON_X_ORIGIN = 190;
	const float BUTTON_Y_ORIGIN = 70;
	const float BUTTON_X_POSITION = 415;
	const float BUTTON_Y_POSITION = 120;
	const float CURSOR_X_ORIGIN = 17;
	const float CURSOR_Y_ORIGIN = 21;

	bool isSelected_Button_start = false;
	bool isSelected_Button_info = false;
	bool isSelected_Button_exit = false;

	/// MENU * ///

	/// INTEGRITY VALIDATOR ///

	void check_integrity();

	/// INTEGRITY VALIDATOR * ///
};

