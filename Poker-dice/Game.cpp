#include "Game.h"

void Game::play_again()
{
    isOnThrow = false;
    isAfterFirstThrow = false;
    for (int i = 0; i <= 4; i++) isDiceChosen[i] = false;
    for (int i = 0; i <= 5; i++) isPair[i] = false;
    for (int i = 0; i <= 5; i++) isPair_enemy[i] = false;
    isThreesome = false;
    isPair_Threesome = false;
    isThreesome_enemy = false;
    isPair_Threesome_enemy = false;
    isAnyChosen = false;
    for (int i = 0; i <= 4; i++) doThrowAgain[i] = false;
    doCheckScore = false;
    isEnd = false;

    for (int i = 0; i <= 4; i++) number[i] = false;
    for (int i = 0; i <= 4; i++) number_enemy[i] = false;

    for (int i = 0; i <= 4; i++) values[i] = false;
    for (int i = 0; i <= 4; i++) values_enemy[i] = false;

    for (int i = 0; i <= 5; i++) result[i] = false;
    for (int i = 0; i <= 5; i++) result_enemy[i] = false;

    int score = 0, score_enemy = 0;

    text_status.setFont(font_default);
    text_status.setPosition(TEXT_STATUS_X_POSITION, TEXT_STATUS_Y_POSITION);
    text_status.setString(L"RZUÆ KOŒCMI");
    text_status.setCharacterSize(80);

    text_result_enemy.setFont(font_default);
    text_result_enemy.setPosition(TEXT_RESULT_ENEMY_X_POSITION, TEXT_RESULT_ENEMY_Y_POSITION);
    text_result_enemy.setString(L"TU WYŒWIETLI SIÊ WYNIK PRZECIWNIKA");
    text_result_enemy.setCharacterSize(42);

    text_result.setFont(font_default);
    text_result.setPosition(TEXT_RESULT_X_POSITION, TEXT_RESULT_Y_POSITION);
    text_result.setString(L"TU WYŒWIETLI SIÊ TWÓJ WYNIK");
    text_result.setCharacterSize(42);

    text_end.setString(L" ");

    sprite_throw.scale(0.9, 0.9);
}

void Game::summary()
{

    if (score>score_enemy)
    {
        text_status.setCharacterSize(80);
        text_status.setPosition(TEXT_STATUS_X_POSITION + 25, TEXT_STATUS_Y_POSITION);
        text_status.setString(L"WYGRA£EŒ!");
    }
    else if (score_enemy>score)
    {
        text_status.setCharacterSize(80);
        text_status.setPosition(TEXT_STATUS_X_POSITION - 20, TEXT_STATUS_Y_POSITION);
        text_status.setString(L"PRZEGRA£EŒ...");
    }
    else if (score==score_enemy)
    {
        text_status.setCharacterSize(80);
        text_status.setPosition(TEXT_STATUS_X_POSITION + 150, TEXT_STATUS_Y_POSITION);
        text_status.setString(L"REMIS");
    }
}

void Game::reset()
{
    for (int i = 0; i <= 4; i++) { values[i] = 0; values_enemy[i] = 0; doThrowAgain[i] = 0; }
    for (int i = 0; i <= 5; i++) { result[i] = 0; result_enemy[i] = 0; }

    isThreesome = false;
    isPair_Threesome = false;

    isThreesome_enemy = false;
    isPair_Threesome_enemy = false;
}

void Game::second_throw()
{
    int a = 0;

    for (int i = 0; i <= 4; i++)
    {
        a = rand() % 2 + 1;
        if (a == 2) doThrowAgain[i] = true;
    }

    sound_shuffle.play();

    text_status.setCharacterSize(80);
    text_status.setPosition(TEXT_STATUS_X_POSITION - 60, TEXT_STATUS_Y_POSITION);
    text_status.setString(L"KOŒCI W RUCHU!");
    window.clear();

    animation_second_throw_speed();
    animation_second_throw_normal();
    animation_second_throw_slow();

    doCheckScore = true;
}

void Game::animation_second_throw_slow()
{
    Sleep(100);

    random_and_set_only_enemy();
    random_and_set_only_player();

    window.draw(background);

    for (int j = 0; j <= 4; j++) window.draw(dice[j]);

    for (int k = 0; k <= 4; k++) window.draw(dice_enemy[k]);

    window.draw(rectangle_status);
    window.draw(text_status);

    window.draw(sprite_throw);
    window.draw(cursor2);

    window.display();

    sound_throw.play();
}

void Game::animation_second_throw_normal()
{
    for (int i = 0; i < 3; i++)
    {

        random_and_set_only_enemy();
        random_and_set_only_player();

        window.draw(background);

        for (int j = 0; j <= 4; j++) window.draw(dice[j]);

        for (int k = 0; k <= 4; k++) window.draw(dice_enemy[k]);

        window.draw(rectangle_status);
        window.draw(text_status);

        window.draw(sprite_throw);
        window.draw(cursor2);

        window.display();

        Sleep(200);
    }
}

void Game::animation_second_throw_speed()
{
    for (int i = 0; i < 6; i++)
    {
        random_and_set_only_enemy();
        random_and_set_only_player();

        window.draw(background);

        for (int j = 0; j <= 4; j++) window.draw(dice[j]);
        for (int k = 0; k <= 4; k++) window.draw(dice_enemy[k]);

        window.draw(rectangle_status);
        window.draw(text_status);

        window.draw(sprite_throw);
        window.draw(cursor2);

        window.display();

        Sleep(100);
    }
}

void Game::random_and_set_only_player()
{
    for (int i = 0; i <= 4; i++) number[i] = rand() % 6 + 1;

    for (int i = 0; i <= 4; i++) if (number[i] == 1 && isDiceChosen[i]) dice[i].setTexture(texture_dice[0]);
    for (int i = 0; i <= 4; i++) if (number[i] == 2 && isDiceChosen[i]) dice[i].setTexture(texture_dice[1]);
    for (int i = 0; i <= 4; i++) if (number[i] == 3 && isDiceChosen[i]) dice[i].setTexture(texture_dice[2]);
    for (int i = 0; i <= 4; i++) if (number[i] == 4 && isDiceChosen[i]) dice[i].setTexture(texture_dice[3]);
    for (int i = 0; i <= 4; i++) if (number[i] == 5 && isDiceChosen[i]) dice[i].setTexture(texture_dice[4]);
    for (int i = 0; i <= 4; i++) if (number[i] == 6 && isDiceChosen[i]) dice[i].setTexture(texture_dice[5]);
}

void Game::second_throw_only_enemy()
{
    int a = 0;

    for (int i = 0; i <= 4; i++)
    {
        a = rand() % 2 + 1;
        if (a == 2) doThrowAgain[i] = true;
    }

    sound_shuffle.play();

    text_status.setCharacterSize(80);
    text_status.setPosition(TEXT_STATUS_X_POSITION - 60, TEXT_STATUS_Y_POSITION);
    text_status.setString(L"KOŒCI W RUCHU!");
    window.clear();

    animation_only_enemy_speed();
    animation_only_enemy_normal();
    animation_only_enemy_slow();

    doCheckScore = true;

}

void Game::random_and_set_only_enemy()
{
    for (int i = 0; i <= 4; i++) number_enemy[i] = rand() % 6 + 1;

    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 1 && doThrowAgain[i]) dice_enemy[i].setTexture(texture_dice[0]);
    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 2 && doThrowAgain[i]) dice_enemy[i].setTexture(texture_dice[1]);
    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 3 && doThrowAgain[i]) dice_enemy[i].setTexture(texture_dice[2]);
    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 4 && doThrowAgain[i]) dice_enemy[i].setTexture(texture_dice[3]);
    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 5 && doThrowAgain[i]) dice_enemy[i].setTexture(texture_dice[4]);
    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 6 && doThrowAgain[i]) dice_enemy[i].setTexture(texture_dice[5]);
}

void Game::animation_only_enemy_slow()
{
    Sleep(100);

    random_and_set_only_enemy();

    window.draw(background);

    for (int j = 0; j <= 4; j++) window.draw(dice[j]);

    for (int k = 0; k <= 4; k++) window.draw(dice_enemy[k]);

    window.draw(rectangle_status);
    window.draw(text_status);

    window.draw(sprite_throw);
    window.draw(cursor2);

    window.display();

    sound_throw.play();
}

void Game::animation_only_enemy_normal()
{
    for (int i = 0; i < 3; i++)
    {

        random_and_set_only_enemy();

        window.draw(background);

        for (int j = 0; j <= 4; j++) window.draw(dice[j]);

        for (int k = 0; k <= 4; k++) window.draw(dice_enemy[k]);

        window.draw(rectangle_status);
        window.draw(text_status);

        window.draw(sprite_throw);
        window.draw(cursor2);

        window.display();

        Sleep(200);
    }
}

void Game::animation_only_enemy_speed()
{
    for (int i = 0; i < 6; i++)
    {
        random_and_set_only_enemy();

        window.draw(background);

        for (int j = 0; j <= 4; j++) window.draw(dice[j]);
        for (int k = 0; k <= 4; k++) window.draw(dice_enemy[k]);

        window.draw(rectangle_status);
        window.draw(text_status);

        window.draw(sprite_throw);
        window.draw(cursor2);

        window.display();

        Sleep(100);
    }
}

void Game::poker_enemy()
{
    text_result_enemy.setString("Poker!");
    text_result_enemy.setCharacterSize(80);
    text_result_enemy.setPosition(TEXT_RESULT_ENEMY_X_POSITION + 320, TEXT_RESULT_ENEMY_Y_POSITION - 25);
    score_enemy = 8;
}

void Game::four_mesh_enemy()
{
    text_result_enemy.setString("Kareta");
    text_result_enemy.setCharacterSize(80);
    text_result_enemy.setPosition(TEXT_RESULT_ENEMY_X_POSITION + 300, TEXT_RESULT_ENEMY_Y_POSITION - 30);
    score_enemy = 7;
}

void Game::full_enemy()
{
    text_result_enemy.setString("Full");
    text_result_enemy.setCharacterSize(80);
    text_result_enemy.setPosition(TEXT_RESULT_ENEMY_X_POSITION + 350, TEXT_RESULT_ENEMY_Y_POSITION - 20);
    score_enemy = 6;
}

void Game::big_straight_enemy()
{
    text_result_enemy.setString("Duzy Strit");
    text_result_enemy.setCharacterSize(80);
    text_result_enemy.setPosition(TEXT_RESULT_ENEMY_X_POSITION + 250, TEXT_RESULT_ENEMY_Y_POSITION - 25);
    score_enemy = 5;
}

void Game::small_straight_enemy()
{
    text_result_enemy.setString("Strit");
    text_result_enemy.setCharacterSize(80);
    text_result_enemy.setPosition(TEXT_RESULT_ENEMY_X_POSITION + 350, TEXT_RESULT_ENEMY_Y_POSITION - 20);
    score_enemy = 4;
}

void Game::threesome_enemy()
{
    text_result_enemy.setString("Trójka");
    text_result_enemy.setCharacterSize(80);
    text_result_enemy.setPosition(TEXT_RESULT_ENEMY_X_POSITION + 300, TEXT_RESULT_ENEMY_Y_POSITION - 25);
    score_enemy = 3;
}

void Game::two_couples_enemy()
{
    text_result_enemy.setString("Dwie Pary");
    text_result_enemy.setCharacterSize(80);
    text_result_enemy.setPosition(TEXT_RESULT_ENEMY_X_POSITION + 250, TEXT_RESULT_ENEMY_Y_POSITION - 30);
    score_enemy = 2;
}

void Game::pair_enemy()
{
    text_result_enemy.setString("Para");
    text_result_enemy.setCharacterSize(80);
    text_result_enemy.setPosition(TEXT_RESULT_ENEMY_X_POSITION + 350, TEXT_RESULT_ENEMY_Y_POSITION - 30);
    score_enemy = 1;
}

void Game::poker()
{
    text_result.setString("Poker!");
    text_result.setCharacterSize(80);
    text_result.setPosition(TEXT_RESULT_X_POSITION + 230, TEXT_RESULT_Y_POSITION - 35);
    score = 8;
}

void Game::four_mesh()
{
    text_result.setString("Kareta");
    text_result.setCharacterSize(80);
    text_result.setPosition(TEXT_RESULT_X_POSITION + 210, TEXT_RESULT_Y_POSITION - 35);
    score = 7;
}

void Game::full()
{
    text_result.setString("Full");
    text_result.setCharacterSize(80);
    text_result.setPosition(TEXT_RESULT_X_POSITION + 250, TEXT_RESULT_Y_POSITION - 35);
    score = 6;
}

void Game::big_straight()
{
    text_result.setString("Duzy Strit");
    text_result.setCharacterSize(80);
    text_result.setPosition(TEXT_RESULT_X_POSITION + 150, TEXT_RESULT_Y_POSITION - 35);
    score = 5;
}

void Game::small_straight()
{
    text_result.setString("Strit");
    text_result.setCharacterSize(80);
    text_result.setPosition(TEXT_RESULT_X_POSITION + 260, TEXT_RESULT_Y_POSITION - 35);
    score = 4;
}

void Game::threesome()
{
    text_result.setString("Trójka");
    text_result.setCharacterSize(80);
    text_result.setPosition(TEXT_RESULT_X_POSITION + 220, TEXT_RESULT_Y_POSITION - 35);
    score = 3;
}

void Game::two_couples()
{
    text_result.setString("Dwie Pary");
    text_result.setCharacterSize(80);
    text_result.setPosition(TEXT_RESULT_X_POSITION + 155, TEXT_RESULT_Y_POSITION - 40);
    score = 2;
}

void Game::pair()
{
        text_result.setString("Para");
        text_result.setCharacterSize(80);
        text_result.setPosition(TEXT_RESULT_X_POSITION + 250, TEXT_RESULT_Y_POSITION - 30);
        score = 1;
}

void Game::check_result()
{
    text_result.setString("Nic");
    text_result.setCharacterSize(80);
    text_result.setPosition(TEXT_RESULT_X_POSITION + 280, TEXT_RESULT_Y_POSITION - 30);
    score = 0;

    for (int i = 0; i <= 4; i++) if (values[i] == 1) result[0]++;
    for (int i = 0; i <= 4; i++) if (values[i] == 2) result[1]++;
    for (int i = 0; i <= 4; i++) if (values[i] == 3) result[2]++;
    for (int i = 0; i <= 4; i++) if (values[i] == 4) result[3]++;
    for (int i = 0; i <= 4; i++) if (values[i] == 5) result[4]++;
    for (int i = 0; i <= 4; i++) if (values[i] == 6) result[5]++;

    for (int i = 0; i <= 5; i++) if (result[i] == 2) isPair[i] = true; else isPair[i] = false;
   
    for (int i = 0; i <= 5; i++) if (result[i] == 2) pair();

    //TWO_COUPLES//
    for (int i = 0; i <= 5; i++) if (isPair[0] == true && isPair[i + 1] == true) two_couples();

    if (isPair[1] == true && isPair[0] == true) two_couples();
    else for (int i = 2; i <= 5; i++) if (isPair[1] == true && isPair[i] == true) two_couples(); 
        
    for (int i = 0; i <= 1; i++) if (isPair[2] == true && isPair[i] == true) two_couples();
    else for (int i = 3; i <= 5; i++) if (isPair[2] == true && isPair[i] == true) two_couples();

    for (int i = 0; i <= 2; i++) if (isPair[3] == true && isPair[i] == true) two_couples();
    else for (int i = 4; i <= 5; i++) if (isPair[3] == true && isPair[i] == true) two_couples();

    for (int i = 0; i <= 3; i++) if (isPair[4] == true && isPair[i] == true) two_couples();
    else if (isPair[4] == true && isPair[5] == true) two_couples();

    for (int i = 0; i <= 4; i++) if (isPair[5] == true && isPair[i] == true) two_couples();
    //TWO_COUPLES*//
    
    for (int i = 0; i <= 5; i++) if (result[i] == 3) threesome();
    if  (result[0] == 1 && result[1] == 2 && result[2] == 3 && result[3] == 4 && result[4] == 5) small_straight();
    if (result[1] == 2 && result[2] == 3 && result[3] == 4 && result[4] == 5 && result[5] == 6) big_straight();

    //FULL//

    for (int i = 0; i <= 5; i++) if (result[i] == 2) isPair_Threesome = true;
    for (int i = 0; i <= 5; i++) if (result[i] == 3) isThreesome = true;

    if (isThreesome && isPair_Threesome) full();

    //FULL*//

    for (int i = 0; i <= 5; i++) if (result[i] == 4) four_mesh();

    for (int i = 0; i <= 5; i++) if (result[i] == 5) poker();

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    text_result_enemy.setString("Nic");
    text_result_enemy.setCharacterSize(80);
    text_result_enemy.setPosition(TEXT_RESULT_ENEMY_X_POSITION + 350, TEXT_RESULT_ENEMY_Y_POSITION - 30);
    score_enemy = 0;

    for (int i = 0; i <= 4; i++) if (values_enemy[i] == 1) result_enemy[0]++;
    for (int i = 0; i <= 4; i++) if (values_enemy[i] == 2) result_enemy[1]++;
    for (int i = 0; i <= 4; i++) if (values_enemy[i] == 3) result_enemy[2]++;
    for (int i = 0; i <= 4; i++) if (values_enemy[i] == 4) result_enemy[3]++;
    for (int i = 0; i <= 4; i++) if (values_enemy[i] == 5) result_enemy[4]++;
    for (int i = 0; i <= 4; i++) if (values_enemy[i] == 6) result_enemy[5]++;

    for (int i = 0; i <= 5; i++) if (result_enemy[i] == 2) isPair_enemy[i] = true; else isPair_enemy[i] = false;


   for (int i = 0; i <= 5; i++) if (result_enemy[i] == 2) pair_enemy();

   //TWO_COUPLES//
   for (int i = 1; i <= 5; i++) if (isPair_enemy[0] == true && isPair_enemy[i] == true) two_couples_enemy();

   if (isPair_enemy[1] == true && isPair_enemy[0] == true) two_couples_enemy();
   else for (int i = 2; i <= 5; i++) if (isPair_enemy[1] == true && isPair_enemy[i] == true) two_couples_enemy();

   for (int i = 0; i <= 1; i++) if (isPair_enemy[2] == true && isPair_enemy[i] == true) two_couples_enemy();
   else for (int i = 3; i <= 5; i++) if (isPair_enemy[2] == true && isPair_enemy[i] == true) two_couples_enemy();

   for (int i = 0; i <= 2; i++) if (isPair_enemy[3] == true && isPair_enemy[i] == true) two_couples_enemy();
   else for (int i = 4; i <= 5; i++) if (isPair_enemy[3] == true && isPair_enemy[i] == true) two_couples_enemy();

   for (int i = 0; i <= 3; i++) if (isPair_enemy[4] == true && isPair_enemy[i] == true) two_couples_enemy();
   else if (isPair_enemy[4] == true && isPair_enemy[5] == true) two_couples_enemy();

   for (int i = 0; i <= 4; i++) if (isPair_enemy[5] == true && isPair_enemy[i] == true) two_couples_enemy();
   //TWO_COUPLES*//

   for (int i = 0; i <= 5; i++) if (result_enemy[i] == 3) threesome_enemy();
   if (result_enemy[0] == 1 && result_enemy[1] == 2 && result_enemy[2] == 3 && result_enemy[3] == 4 && result_enemy[4] == 5) small_straight_enemy();
   if (result_enemy[1] == 2 && result_enemy[2] == 3 && result_enemy[3] == 4 && result_enemy[4] == 5 && result_enemy[5] == 6) big_straight_enemy();

   //FULL//

   for (int i = 0; i <= 5; i++) if (result_enemy[i] == 2) isPair_Threesome_enemy = true;
   for (int i = 0; i <= 5; i++) if (result_enemy[i] == 3) isThreesome_enemy = true;

   if (isThreesome_enemy && isPair_Threesome_enemy) full_enemy();

   //FULL*//

   for (int i = 0; i <= 5; i++) if (result_enemy[i] == 4) four_mesh_enemy();

   for (int i = 0; i <= 5; i++) if (result_enemy[i] == 5) poker_enemy();    
}

void Game::set_chosen_hover(int index)
{
    for (int i = 0; i <= 5; i++) if (values[index] == i + 1) dice[index].setTexture(texture_dice_chosen_hover[i]);
}

void Game::set_chosen(int index)
{
    for (int i = 0; i <= 5; i++) if (values[index] == i + 1) dice[index].setTexture(texture_dice_chosen[i]);
}

void Game::set_back(int index)
{
    for (int i = 0; i <= 5; i++) if (values[index] == i + 1) dice[index].setTexture(texture_dice[i]);
}

void Game::set_hover(int index)
{
    for (int i = 0; i <= 5; i++) if (values[index] == i + 1) dice[index].setTexture(texture_dice_hover[i]);
}

void Game::check_value()
{
    for (int i = 0; i <= 5; i++) if (dice[0].getTexture() == &texture_dice[i]) values[0] = i + 1;
    for (int i = 0; i <= 5; i++) if (dice[1].getTexture() == &texture_dice[i]) values[1] = i + 1;
    for (int i = 0; i <= 5; i++) if (dice[2].getTexture() == &texture_dice[i]) values[2] = i + 1;
    for (int i = 0; i <= 5; i++) if (dice[3].getTexture() == &texture_dice[i]) values[3] = i + 1;
    for (int i = 0; i <= 5; i++) if (dice[4].getTexture() == &texture_dice[i]) values[4] = i + 1;

    for (int i = 0; i <= 5; i++) if (dice_enemy[0].getTexture() == &texture_dice[i]) values_enemy[0] = i + 1;
    for (int i = 0; i <= 5; i++) if (dice_enemy[1].getTexture() == &texture_dice[i]) values_enemy[1] = i + 1;
    for (int i = 0; i <= 5; i++) if (dice_enemy[2].getTexture() == &texture_dice[i]) values_enemy[2] = i + 1;
    for (int i = 0; i <= 5; i++) if (dice_enemy[3].getTexture() == &texture_dice[i]) values_enemy[3] = i + 1;
    for (int i = 0; i <= 5; i++) if (dice_enemy[4].getTexture() == &texture_dice[i]) values_enemy[4] = i + 1;
}

void Game::first_throw()
{
    sound_shuffle.play();

    text_status.setCharacterSize(80);
    text_status.setPosition(TEXT_STATUS_X_POSITION - 60, TEXT_STATUS_Y_POSITION);
    text_status.setString(L"KOŒCI W RUCHU!");
    window.clear();

    animation_speed();
    animation_normal();
    animation_slow();

    text_status.setCharacterSize(40);
    text_status.setString(L"WYBIERZ I PRZERZUÆ KOŒCI LUB POMIÑ");
    text_status.setPosition(TEXT_STATUS_X_POSITION - 125, TEXT_STATUS_Y_POSITION + 25);

    isAfterFirstThrow = true;
}

void Game::animation_slow()
{
    Sleep(100);

    random_and_set();

    window.draw(background);

    for (int j = 0; j <= 4; j++) window.draw(dice[j]);

    for (int k = 0; k <= 4; k++) window.draw(dice_enemy[k]);

    window.draw(rectangle_status);
    window.draw(text_status);

    window.draw(sprite_throw);
    window.draw(cursor2);

    window.display();

    sound_throw.play();
}

void Game::animation_normal()
{
    for (int i = 0; i < 3; i++)
    {

        random_and_set();

        window.draw(background);

        for (int j = 0; j <= 4; j++) window.draw(dice[j]);

        for (int k = 0; k <= 4; k++) window.draw(dice_enemy[k]);

        window.draw(rectangle_status);
        window.draw(text_status);

        window.draw(sprite_throw);
        window.draw(cursor2);

        window.display();

        Sleep(200);
    }
}

void Game::animation_speed()
{
    for (int i = 0; i < 6; i++)
    {

        random_and_set();

        window.draw(background);

        for (int j = 0; j <= 4; j++) window.draw(dice[j]);

        for (int k = 0; k <= 4; k++) window.draw(dice_enemy[k]);

        window.draw(rectangle_status);
        window.draw(text_status);

        window.draw(sprite_throw);
        window.draw(cursor2);

        window.display();

        Sleep(100);
    }
}

void Game::random_and_set()
{
    for (int i = 0; i <= 4; i++) number[i] = rand() % 6 + 1;
    for (int i = 0; i <= 4; i++) number_enemy[i] = rand() % 6 + 1;
    
    for (int i = 0; i <= 4; i++) if (number[i] == 1) dice[i].setTexture(texture_dice[0]);
    for (int i = 0; i <= 4; i++) if (number[i] == 2) dice[i].setTexture(texture_dice[1]);
    for (int i = 0; i <= 4; i++) if (number[i] == 3) dice[i].setTexture(texture_dice[2]);
    for (int i = 0; i <= 4; i++) if (number[i] == 4) dice[i].setTexture(texture_dice[3]);
    for (int i = 0; i <= 4; i++) if (number[i] == 5) dice[i].setTexture(texture_dice[4]);
    for (int i = 0; i <= 4; i++) if (number[i] == 6) dice[i].setTexture(texture_dice[5]);

    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 1) dice_enemy[i].setTexture(texture_dice[0]);
    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 2) dice_enemy[i].setTexture(texture_dice[1]);
    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 3) dice_enemy[i].setTexture(texture_dice[2]);
    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 4) dice_enemy[i].setTexture(texture_dice[3]);
    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 5) dice_enemy[i].setTexture(texture_dice[4]);
    for (int i = 0; i <= 4; i++) if (number_enemy[i] == 6) dice_enemy[i].setTexture(texture_dice[5]);
}

void Game::process()
{ 
    window.create(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height, 32), "Poker dice 1.0", Style::Fullscreen);
    window.setActive(true);
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) exit(0);

            if (isEnd) 
            {
                text_end.setString(L"NACIŒNIJ SPACJÊ, BY ZAGRAÆ PONOWNIE LUB ESCAPE, BY WYJŒÆ");
                if (Keyboard::isKeyPressed(Keyboard::Space)) play_again();
            }
           
            if (doCheckScore) summary();

            for (int i = 0; i <= 4; i++)
            {
                if (isDiceChosen[i])
                {
                    if ((dice[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))))
                    {
                        set_chosen_hover(i);
                        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right)
                        {
                            isDiceChosen[i] = false;
                        }
                    }
                    else if (!(dice[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))) set_chosen(i);
                }
            }
            if (isAfterFirstThrow && !(isEnd))
            {
                for (int i = 0; i <= 4; i++)
                {
                    if ((dice[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) && !(isDiceChosen[i]))
                    {
                        set_hover(i);
                        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) isDiceChosen[i] = true;
                    }
                    else if (!(dice[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) && !(isDiceChosen[i]))
                        set_back(i);
                }

                if ((sprite_throw.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))))
                {
                    if (clock04.getElapsedTime().asMilliseconds() > 20)
                    {
                        sound_grab.setLoop(false);
                    }
                    else
                    {
                        sound_grab.play();
                    }


                    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
                    {
                        for (int i = 0; i <= 4; i++) if (isDiceChosen[i]) isAnyChosen = true;
                        if (!(isAnyChosen))
                        {
                            reset();
                            second_throw_only_enemy();
                            check_value();
                            check_result();
                            isEnd = true;
                        }
                        else
                        {
                            reset();
                            second_throw();
                            check_value();
                            check_result();
                            for (int i = 0; i <= 4; i++) isDiceChosen[i] = false;
                            isEnd = true;
                        }
                    }

                    if (!(isOnThrow))
                    {
                        sprite_throw.scale(1.1, 1.1);
                        isOnThrow = true;
                    }
                }
                else if (!((sprite_throw.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))) && isOnThrow == true)
                {
                    sprite_throw.scale(0.9, 0.9);
                    isOnThrow = false;

                }
                else
                {
                    sound_grab.setLoop(false);
                    clock04.restart();
                }
            }

            if (!(isAfterFirstThrow))
            {

                if ((sprite_throw.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))))
                {
                    if (clock04.getElapsedTime().asMilliseconds() > 20)
                    {
                        sound_grab.setLoop(false);
                    }
                    else
                    {
                        sound_grab.play();
                    }


                    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
                    {
                        srand(time(NULL));
                        first_throw();
                        check_value();
                        check_result();
                    }

                    if (!(isOnThrow))
                    {
                        sprite_throw.scale(1.1, 1.1);
                        isOnThrow = true;
                    }
                }
                else if (!((sprite_throw.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))) && isOnThrow == true)
                {
                    sprite_throw.scale(0.9, 0.9);
                    isOnThrow = false;

                }
                else
                {
                    sound_grab.setLoop(false);
                    clock04.restart();
                }
            }
        }

        mousePos = Mouse::getPosition(window);
        cursor2.setPosition((float)mousePos.x, (float)mousePos.y);

        window.draw(background);

        for (int i = 0; i <= 4; i++) window.draw(dice[i]);

        for (int i = 0; i <= 4; i++) window.draw(dice_enemy[i]);

        window.draw(rectangle_status);
        window.draw(rectangle_result_enemy);
        window.draw(rectangle_result);

        window.draw(text_status);
        window.draw(text_result_enemy);
        window.draw(text_result);
        window.draw(text_end);

        window.draw(sprite_throw);
        window.draw(cursor2);

        window.display();
    }
}

void Game::configure_process()
{
    texture_rectangle.loadFromFile("graphics/rectangle.png");

    font_default.loadFromFile("fonts/NewRocker-Regular.ttf");

    texture_background.loadFromFile("graphics/background.jpeg");

    texture_cursor2.loadFromFile("graphics/cursor2.png");

    texture_throw.loadFromFile("graphics/throw.png");

    texture_dice[0].loadFromFile("graphics/diceOne.png");
    texture_dice[1].loadFromFile("graphics/diceTwo.png");
    texture_dice[2].loadFromFile("graphics/diceThree.png");
    texture_dice[3].loadFromFile("graphics/diceFour.png");
    texture_dice[4].loadFromFile("graphics/diceFive.png");
    texture_dice[5].loadFromFile("graphics/diceSix.png");
    

    sound_buffer_grab.loadFromFile("audio/dieGrab.wav");
    sound_buffer_throw.loadFromFile("audio/dieThrow.wav");
    sound_buffer_shuffle.loadFromFile("audio/dieShuffle.wav");

    texture_dice_hover[0].loadFromFile("graphics/diceOneHover.png");
    texture_dice_hover[1].loadFromFile("graphics/diceTwoHover.png");
    texture_dice_hover[2].loadFromFile("graphics/diceThreeHover.png");
    texture_dice_hover[3].loadFromFile("graphics/diceFourHover.png");
    texture_dice_hover[4].loadFromFile("graphics/diceFiveHover.png");
    texture_dice_hover[5].loadFromFile("graphics/diceSixHover.png");
    

    texture_dice_chosen[0].loadFromFile("graphics/diceOneChosen.png");
    texture_dice_chosen[1].loadFromFile("graphics/diceTwoChosen.png");
    texture_dice_chosen[2].loadFromFile("graphics/diceThreeChosen.png");
    texture_dice_chosen[3].loadFromFile("graphics/diceFourChosen.png");
    texture_dice_chosen[4].loadFromFile("graphics/diceFiveChosen.png");
    texture_dice_chosen[5].loadFromFile("graphics/diceSixChosen.png");
   

    texture_dice_chosen_hover[0].loadFromFile("graphics/diceOneChosenHover.png");
    texture_dice_chosen_hover[1].loadFromFile("graphics/diceTwoChosenHover.png");
    texture_dice_chosen_hover[2].loadFromFile("graphics/diceThreeChosenHover.png");
    texture_dice_chosen_hover[3].loadFromFile("graphics/diceFourChosenHover.png");
    texture_dice_chosen_hover[4].loadFromFile("graphics/diceFiveChosenHover.png");
    texture_dice_chosen_hover[5].loadFromFile("graphics/diceSixChosenHover.png");

    // ---------------------------------------------------------------------------------------- //

    rectangle_status.setTexture(texture_rectangle);
    rectangle_result_enemy.setTexture(texture_rectangle);
    rectangle_result.setTexture(texture_rectangle);

    text_status.setFont(font_default);
    text_status.setPosition(TEXT_STATUS_X_POSITION, TEXT_STATUS_Y_POSITION);
    text_status.setString(L"RZUÆ KOŒCMI");
    text_status.setCharacterSize(80);

    text_result_enemy.setFont(font_default);
    text_result_enemy.setPosition(TEXT_RESULT_ENEMY_X_POSITION, TEXT_RESULT_ENEMY_Y_POSITION);
    text_result_enemy.setString(L"TU WYŒWIETLI SIÊ WYNIK PRZECIWNIKA");
    text_result_enemy.setCharacterSize(42);

    text_result.setFont(font_default);
    text_result.setPosition(TEXT_RESULT_X_POSITION, TEXT_RESULT_Y_POSITION);
    text_result.setString(L"TU WYŒWIETLI SIÊ TWÓJ WYNIK");
    text_result.setCharacterSize(42);

    text_end.setFont(font_default);
    text_end.setCharacterSize(25);
    text_end.setPosition(TEXT_STATUS_X_POSITION - 125, TEXT_STATUS_Y_POSITION + 100);

    background.setTexture(texture_background);

    for (int i = 0; i <= 4; i++) dice[i].setTexture(texture_dice[i]);
    
    for (int i = 0; i <= 4; i++) dice_enemy[i].setTexture(texture_dice[i]);

    for (int i = 0; i <= 4; i++) dice[i].setOrigin(DICE_X_ORIGIN, DICE_Y_ORIGIN);

    for (int i = 0; i <= 4; i++) dice_enemy[i].setOrigin(DICE_X_ORIGIN, DICE_Y_ORIGIN);

    for (int i = 0; i <= 4; i++) dice[i].setPosition(DICE_X_POSITION + i * 340, DICE_Y_POSITION);

    for (int i = 0; i <= 4; i++) dice_enemy[i].setPosition(DICE_X_POSITION + i * 340, DICE_Y_POSITION - 620);

    cursor2.setTexture(texture_cursor2);
    cursor2.setOrigin(CURSOR2_X_ORIGIN, CURSOR2_Y_ORIGIN);

    sprite_throw.setTexture(texture_throw);
    sprite_throw.setOrigin(THROW_X_ORIGIN, THROW_Y_ORIGIN);
    sprite_throw.setPosition(THROW_X_POSITION, THROW_Y_POSITION);
    sprite_throw.scale(0.5, 0.5);

    rectangle_status.setOrigin(RECTANGLE_X_ORIGIN, RECTANGLE_Y_ORIGIN);
    rectangle_status.setPosition(RECTANGLE_X_POSITION, RECTANGLE_Y_POSITION);
    rectangle_status.scale(0.8, 0.5);

    rectangle_result_enemy.setOrigin(RECTANGLE_X_ORIGIN, RECTANGLE_Y_ORIGIN);
    rectangle_result_enemy.setPosition(RECTANGLE_X_POSITION, 0);
    rectangle_result_enemy.scale(0.8, 0.5);

    rectangle_result.setOrigin(RECTANGLE_X_ORIGIN, RECTANGLE_Y_ORIGIN);
    rectangle_result.setPosition(RECTANGLE_X_POSITION, 1080);
    rectangle_result.scale(0.8, 0.5);

    sound_grab.setBuffer(sound_buffer_grab);
    sound_throw.setBuffer(sound_buffer_throw);
    sound_shuffle.setBuffer(sound_buffer_shuffle);

    process();

}

void Game::menu()
{
    window.create(VideoMode(WINDOW_X_SIZE, WINDOW_Y_SIZE, 32), "Poker dice 1.0", Style::Close);
    window.setActive(true);
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) exit(0);

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Down)
                {
                    if (!button_start.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))
                        && !button_info.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))
                        && !button_exit.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) {
                        sound_sound_button.play();
                    }
                    which_chosen++;
                    if (which_chosen >= 4)
                    {
                        which_chosen = 1;
                    }
                }
                if (event.key.code == Keyboard::Up)
                {
                    if (!button_start.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))
                        && !button_info.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))
                        && !button_exit.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) {
                        sound_sound_button.play();
                    }
                    which_chosen--;
                    if (which_chosen <= -1 || which_chosen <= 0)
                    {
                        which_chosen = 3;
                    }
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::Enter))
            {
                if (which_chosen == 1)
                {
                    sound_clicked_sound.play();
                    Sleep(500);
                    window.close();
                    configure_process();
                }
                if (which_chosen == 2)
                {
                    ShowWindow(window.getSystemHandle(), SW_MINIMIZE);
                    sound_clicked_sound.play();
                    Sleep(500);
                    ShellExecute(0, 0, L"info.txt", 0, 0, SW_SHOW);
                    ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
                }
                if (which_chosen == 3)
                {
                    sound_clicked_sound.play();
                    Sleep(500);
                    window.close();
                    exit(0);
                }
            }
        }

        if (button_start.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
        {
            if (!(which_chosen == 0))
            {
                which_chosen = 0;
            }
            isSelected_Button_start = true;
            isSelected_Button_info = false;
            isSelected_Button_exit = false;
            if (clock01.getElapsedTime().asMilliseconds() > 20)
            {
                sound_sound_button.setLoop(false);
            }
            else
            {
                sound_sound_button.play();
            }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                sound_clicked_sound.play();
                Sleep(500);
                window.close();
                configure_process();
            }
        }
        else
        {
            sound_sound_button.setLoop(false);
            clock01.restart();
        }

        if (!button_start.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) isSelected_Button_start = false;

        if (button_info.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
        {
            if (!(which_chosen == 0))
            {
                which_chosen = 0;
            }
            isSelected_Button_start = false;
            isSelected_Button_info = true;
            isSelected_Button_exit = false;
            if (clock02.getElapsedTime().asMilliseconds() > 20)
            {
                sound_sound_button.setLoop(false);
            }
            else
            {
                sound_sound_button.play();
            }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                ShowWindow(window.getSystemHandle(), SW_MINIMIZE);
                sound_clicked_sound.play();
                Sleep(500);
                ShellExecute(0, 0, L"info.txt", 0, 0, SW_SHOW);
                ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
            }

        }
        else
        {
            sound_sound_button.setLoop(false);
            clock02.restart();
        }

        if (!button_info.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) isSelected_Button_info = false;

        if (button_exit.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
        {
            if (!(which_chosen == 0))
            {
                which_chosen = 0;
            }
            isSelected_Button_start = false;
            isSelected_Button_info = false;
            isSelected_Button_exit = true;
            if (clock03.getElapsedTime().asMilliseconds() > 20)
            {
                sound_sound_button.setLoop(false);
            }
            else
            {
                sound_sound_button.play();
            }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                sound_clicked_sound.play();
                Sleep(500);
                window.close();
                exit(0);
            }

        }
        else
        {
            sound_sound_button.setLoop(false);
            clock03.restart();
        }

        if (!button_exit.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) isSelected_Button_exit = false;

        if (which_chosen == 1)
        {
            if (isSelected_Button_start == false)
            {
                isSelected_Button_info = false;
                isSelected_Button_exit = false;
                isSelected_Button_start = true;
            }
            else if (isSelected_Button_start == true)
            {
                isSelected_Button_info = true;
                isSelected_Button_exit = false;
                isSelected_Button_start = false;
            }
        }

        if (which_chosen == 2)
        {
            if (isSelected_Button_info == false)
            {
                isSelected_Button_info = true;
                isSelected_Button_exit = false;
                isSelected_Button_start = false;
            }
            else if (isSelected_Button_info == true)
            {
                isSelected_Button_info = false;
                isSelected_Button_exit = true;
                isSelected_Button_start = false;
            }
        }

        if (which_chosen == 3)
        {
            if (isSelected_Button_exit == false)
            {
                isSelected_Button_info = false;
                isSelected_Button_exit = true;
                isSelected_Button_start = false;
            }
            else if (isSelected_Button_start == true)
            {
                isSelected_Button_info = false;
                isSelected_Button_exit = false;
                isSelected_Button_start = true;
            }
        }

        if (isSelected_Button_start == true)
        {
            window.draw(button_start_selected);
        }
        else
        {
            window.draw(button_start);
        }
        if (isSelected_Button_info == true)
        {
            window.draw(button_info_selected);
        }
        else
        {
            window.draw(button_info);
        }
        if (isSelected_Button_exit == true)
        {
            window.draw(button_exit_selected);
        }
        else
        {
            window.draw(button_exit);
        }

        mousePos = Mouse::getPosition(window);
        cursor.setPosition((float)mousePos.x, (float)mousePos.y);
        window.draw(cursor);
        window.display();
        window.clear();

    }
}

void Game::configure_menu()
{
    texture_button_start.loadFromFile("graphics/button_start.jpg");
    texture_button_start_selected.loadFromFile("graphics/button_start_selected.jpg");
    texture_button_info.loadFromFile("graphics/button_info.jpg");
    texture_button_info_selected.loadFromFile("graphics/button_info_selected.jpg");
    texture_button_exit.loadFromFile("graphics/button_exit.jpg");
    texture_button_exit_selected.loadFromFile("graphics/button_exit_selected.jpg");

    sound_buffer_sound_button.loadFromFile("audio/sound_button.wav");
    sound_buffer_clicked_sound.loadFromFile("audio/clicked_sound.wav");

    texture_cursor.loadFromFile("graphics/cursor.png");
    // ---------------------------------------------------------------------------------------- //

    cursor.setTexture(texture_cursor);
    cursor.setOrigin(CURSOR_X_ORIGIN, CURSOR_Y_ORIGIN);

    button_start.setTexture(texture_button_start);
    button_start_selected.setTexture(texture_button_start_selected);
    button_info.setTexture(texture_button_info);
    button_info_selected.setTexture(texture_button_info_selected);
    button_exit.setTexture(texture_button_exit);
    button_exit_selected.setTexture(texture_button_exit_selected);

    sound_sound_button.setBuffer(sound_buffer_sound_button);
    sound_clicked_sound.setBuffer(sound_buffer_clicked_sound);

    button_start.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);
    button_start_selected.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);
    button_info.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);
    button_info_selected.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);
    button_exit.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);
    button_exit_selected.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);

    button_start.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION);
    button_start_selected.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION);
    button_info.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION + 200);
    button_info_selected.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION + 200);
    button_exit.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION + 400);
    button_exit_selected.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION + 400);
}

void Game::check_integrity()
{
    if (!experimental::filesystem::exists("info.txt"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("audio/clicked_sound.wav"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("audio/sound_button.wav"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/button_exit.jpg"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/button_exit_selected.jpg"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/button_info.jpg"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/button_info_selected.jpg"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/button_start.jpg"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/button_start_selected.jpg"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/cursor.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/cursor2.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/background.jpeg"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/background.jpeg"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/background.jpeg"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceOne.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceTwo.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceThree.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceFour.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceFive.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceSix.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/throw.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("fonts/NewRocker-Regular.ttf"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/rectangle.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("audio/dieGrab.wav"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("audio/dieThrow.wav"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("audio/dieShuffle.wav"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceOneHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceOneHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceTwoHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceThreeHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceFourHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceFiveHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceSixHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceOneChosen.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceTwoChosen.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceThreeChosen.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceFourChosen.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceFiveChosen.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceSixChosen.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceOneChosenHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceTwoChosenHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceThreeChosenHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceFourChosenHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceFiveChosenHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("graphics/diceSixChosenHover.png"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
    if (!experimental::filesystem::exists("icon.ico"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }

}
