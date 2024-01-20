#include <unistd.h>
#include <ncurses.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include "io.h"
#include "character.h"
#include "poke327.h"
#include "pokemon.h"
using namespace std;
int level;
extern vector<Pokemon> Npc_pokes;
extern vector<Pokemon> player_pokes;
extern int prob;
int pcHp;
int opHp;

int pcHp1;
int opHp1;

void ChangePokemon(){
  clear();
  printw("Which Pokemon are you trying to change? Select numer from 2 - %d\n", player_pokes.size());
  long unsigned int i;
  for(i =0;i< player_pokes.size(); i++){
    printw("the numer: %d pokemon :\n",i+1);
    printw("%s%s%s: HP:%d   ATK:%d   DEF:%d   SPATK:%d   SPDEF:%d   SPEED:%d %s",
                   player_pokes[i].is_shiny() ? "*" : "", player_pokes[i].get_species(),
                   player_pokes[i].is_shiny() ? "*" : "",
                    player_pokes[i].cur_hp, player_pokes[i].get_atk(),
                   player_pokes[i].get_def(), player_pokes[i].get_spatk(), player_pokes[i].get_spdef(),
                   player_pokes[i].get_speed(), player_pokes[i].get_gender_string());
  printw("\n");
  }
  char ch = getch();
  if(ch =='2'){
    swap(player_pokes[0],player_pokes[1]);
    printw("%s%s%s has set to your initial pokemon\n",  player_pokes[0].is_shiny() ? "*" : "", player_pokes[0].get_species(),
                   player_pokes[0].is_shiny() ? "*" : "");
    getch();
  }else if(ch =='3'){
   swap(player_pokes[0],player_pokes[2]);
    printw("%s%s%s has set to your initial pokemon\n",  player_pokes[0].is_shiny() ? "*" : "", player_pokes[0].get_species(),
                   player_pokes[0].is_shiny() ? "*" : "");
    getch();
  }else if(ch =='4'){
   swap(player_pokes[0],player_pokes[3]);
    printw("%s%s%s has set to your initial pokemon\n",  player_pokes[0].is_shiny() ? "*" : "", player_pokes[0].get_species(),
                   player_pokes[0].is_shiny() ? "*" : "");
    getch();
  }else if(ch =='5'){
   swap(player_pokes[0],player_pokes[4]);
    printw("%s%s%s has set to your initial pokemon\n",  player_pokes[0].is_shiny() ? "*" : "", player_pokes[0].get_species(),
                   player_pokes[0].is_shiny() ? "*" : "");
    getch();
  }else if(ch =='6'){
   swap(player_pokes[0],player_pokes[5]);
    printw("%s%s%s has set to your initial pokemon\n",  player_pokes[0].is_shiny() ? "*" : "", player_pokes[0].get_species(),
                   player_pokes[0].is_shiny() ? "*" : "");
    getch();
  }else{
    printw("No such pokemon\n");
  }
}
typedef struct io_message {
  /* Will print " --more-- " at end of line when another message follows. *
   * Leave 10 extra spaces for that.                                      */
  char msg[71];
  struct io_message *next;
} io_message_t;

static io_message_t *io_head, *io_tail;

void api(){
  printw("\n\n\n\n\n\n                 Now its your turn\n");
  printw("          1.Fight             2. Bag ");
  printw("\n");    
  printw("          3.Run               4.Pokemon\n"); 
}
void battleInfo(Pokemon pcPoke, Pokemon wildPoke){
  clear();
  system("Color 16");
  printw("PLAYER:\n");
  // int power1 = pcPoke.get_power(0);
  // int power2 = pcPoke.get_power(1);
  printw("%s%s%s: HP:%d   ATK:%d   DEF:%d   SPATK:%d   SPDEF:%d   SPEED:%d %s",
                   player_pokes[0].is_shiny() ? "*" : "",  player_pokes[0].get_species(),
                   pcPoke.is_shiny() ? "*" : "",
                    player_pokes[0].cur_hp,  player_pokes[0].get_atk(),
                    player_pokes[0].get_def(),  player_pokes[0].get_spatk(),  player_pokes[0].get_spdef(),
                    player_pokes[0].get_speed(),  player_pokes[0].get_gender_string());
  printw("\n");
printw("Opponent\n");
printw("%s%s%s: HP:%d   ATK:%d   DEF:%d   SPATK:%d   SPDEF:%d   SPEED:%d %s",
                   wildPoke.is_shiny() ? "*" : "", wildPoke.get_species(),
                   wildPoke.is_shiny() ? "*" : "", 
                   wildPoke.cur_hp, wildPoke.get_atk(),
                   wildPoke.get_def(), wildPoke.get_spatk(), wildPoke.get_spdef(),
                   wildPoke.get_speed(), wildPoke.get_gender_string());
  printw("\n\n");
}

void movesInfo(Pokemon pcPoke){
  int power1 = pcPoke.get_power(0);
  int power2 = pcPoke.get_power(1);
printw("Please choose your move\n\n");
  printw("%s's 1.moves: %s power:%d\n",pcPoke.get_species(), 
  pcPoke.get_move(0), power1);
  printw("%s's 2.moves: %s power:%d\n",pcPoke.get_species(), 
  pcPoke.get_move(1), power2);
}

bool run( Pokemon *wildPoke){
  int x = rand()%2+1;
  
  if(x == 1){
    return false;
  }else{
    return true;
  }
}


void revives(){
  clear();
  printw("Please select a pokemon to use revives from 1 - %d\n\n",player_pokes.size());
  long unsigned int i ;
  for(i = 0; i< player_pokes.size(); i ++){
    printw("The number %d pokemon  ", i+1);
    printw("%s%s%s: HP:%d \n\n  ",
                   player_pokes[i].is_shiny() ? "*" : "",  player_pokes[i].get_species(),
                   player_pokes[i].is_shiny() ? "*" : "",  player_pokes[i].cur_hp);
  }
  char ch = getch();
  if(ch == '1'){
    player_pokes[0].cur_hp = player_pokes[0].get_hp();
    printw("Now your pokemon hp have revived to %d\n",player_pokes[0].cur_hp);
  }else if(ch == '2'){
     player_pokes[1].cur_hp = player_pokes[1].get_hp();
      printw("Now your pokemon hp have revived to %d\n",player_pokes[1].cur_hp);
  }else if(ch == '3'){
     player_pokes[2].cur_hp = player_pokes[2].get_hp();
      printw("Now your pokemon hp have revived to %d\n",player_pokes[2].cur_hp);
  }else if(ch =='4'){
     player_pokes[3].cur_hp = player_pokes[3].get_hp();
      printw("Now your pokemon hp have revived to %d\n",player_pokes[3].cur_hp);
  }else if(ch =='5'){
     player_pokes[4].cur_hp = player_pokes[4].get_hp();
      printw("Now your pokemon hp have revived to %d\n",player_pokes[4].cur_hp);
  }else if(ch =='6'){
     player_pokes[5].cur_hp = player_pokes[5].get_hp();
      printw("Now your pokemon hp have revived to %d\n",player_pokes[5].cur_hp);
  }
}

void potions(){
  clear();
  printw("Please selection a pokemon to use potions from 1 - %d\n\n",player_pokes.size());
  long unsigned int i ;
  for(i = 0; i< player_pokes.size(); i ++){
    printw("The number %d pokemon  ", i+1);
    printw("%s%s%s: HP:%d \n\n  ",
                   player_pokes[i].is_shiny() ? "*" : "",  player_pokes[i].get_species(),
                   player_pokes[i].is_shiny() ? "*" : "",  player_pokes[i].cur_hp);
  }
  char ch = getch();
  if(ch == '1'){
    player_pokes[0].isDead = false;
    player_pokes[0].cur_hp = player_pokes[0].cur_hp +20;
    if(player_pokes[0].cur_hp > player_pokes[0].get_hp()){
      player_pokes[0].cur_hp = player_pokes[0].get_hp();
    }
    printw("Now your pokemon hp have healed 20 hp to %d\n",player_pokes[0].cur_hp);
  }else if(ch == '2'){
    player_pokes[1].isDead = false;
     player_pokes[1].cur_hp = player_pokes[1].cur_hp +20;
    if(player_pokes[1].cur_hp > player_pokes[1].get_hp()){
      player_pokes[1].cur_hp = player_pokes[1].get_hp();
    }
    printw("Now your pokemon hp have healed 20 hp to %d\n",player_pokes[0].cur_hp);
  }else if(ch == '3'){
    player_pokes[2].isDead = false;
      player_pokes[2].cur_hp = player_pokes[2].cur_hp +20;
    if(player_pokes[2].cur_hp > player_pokes[2].get_hp()){
      player_pokes[2].cur_hp = player_pokes[2].get_hp();
    }
    printw("Now your pokemon hp have healed 20 hp to %d\n",player_pokes[0].cur_hp);
  }else if(ch =='4'){
    player_pokes[3].isDead = false;
      player_pokes[3].cur_hp = player_pokes[3].cur_hp +20;
    if(player_pokes[3].cur_hp > player_pokes[3].get_hp()){
      player_pokes[3].cur_hp = player_pokes[3].get_hp();
    }
    printw("Now your pokemon hp have healed 20 hp to %d\n",player_pokes[0].cur_hp);
  }else if(ch =='5'){
    player_pokes[4].isDead = false;
     player_pokes[4].cur_hp = player_pokes[4].cur_hp +20;
    if(player_pokes[4].cur_hp > player_pokes[4].get_hp()){
      player_pokes[4].cur_hp = player_pokes[4].get_hp();
    }
    printw("Now your pokemon hp have healed 20 hp to %d\n",player_pokes[0].cur_hp);
  }else if(ch =='6'){
    player_pokes[5].isDead = false;
     player_pokes[5].cur_hp = player_pokes[5].cur_hp +20;
    if(player_pokes[5].cur_hp > player_pokes[5].get_hp()){
      player_pokes[5].cur_hp = player_pokes[5].get_hp();
    }
    printw("Now your pokemon hp have healed 20 hp to %d\n",player_pokes[0].cur_hp);
  }
}

bool attackby(Pokemon *pcPoke, Pokemon *oppPoke, int power){
  // int pokeHp = oppPoke->get_hp();
  // int playerHp = pcPoke->get_hp();
   int wildSpeed = oppPoke->get_speed();

  int x = rand()%256;
  int crit;
  
  printw(" Opponent Pokemon use %s \n",oppPoke->get_move(0));
  if(x <= wildSpeed/2){
    crit = oppPoke->get_atk() * 1.5;
  }else{
    crit = oppPoke->get_atk();
  }

int  damageNum =((((2*oppPoke->get_level())/5+2)*power*(pcPoke->get_atk()/oppPoke->get_def()+2))/50)*crit;
 damageNum = rand()%6+1;
  printw("Damage amount %d\n to your pokemon", damageNum);
 // pcHp1 = pcHp1 - damageNum;
  player_pokes[0].cur_hp = player_pokes[0].cur_hp - damageNum;
   printw("Now Your Pokemon pokeHp  : %d\n", player_pokes[0].cur_hp);
  if( player_pokes[0].cur_hp<0){
    player_pokes[0].cur_hp =0;
    pcPoke->isDead =true;
    printw("Now Your Pokemon pokeHp  : %d\n",player_pokes[0].cur_hp);
    printw("Your initial Pokemon dead, please select 1 .another pokemon or 2.run away\n");
    char ch = getch();
    if( ch =='1' ){
      if(player_pokes.size() >1){
      ChangePokemon();
      }else{
        printw("Looks like you have no more fightable pokemon\n\n");
        printw("             You lose the battle\n");
        printw("click anything return");
        getch();
        return true;
      }
    }else if(ch == '2'){
      if(run( oppPoke) == true){
printw("Escape success click anything to return");
      }else{
        printw("Escape failed");
        return false;
      }
  
      return true;
    }
  }
 
   return false;
}
bool Attack(Pokemon pcPoke, Pokemon *wildPoke){
  int power1 = pcPoke.get_power(0);
  int power2 = pcPoke.get_power(1);
  int power;
  int pcSpeed = pcPoke.get_speed();
  int x = rand()%256;
  int crit;
  
  if(x <= pcSpeed/2){
    crit = pcPoke.get_atk() * 1.5;
  }else{
    crit = pcPoke.get_atk();
  }
  printw("\n");
  printw("\n");
  battleInfo(pcPoke,*wildPoke);
  movesInfo(pcPoke);
  char ch = getch();
  if(ch == '1'){
printw("You have chooese 1st move\n\n");
    power = power1;
  }else if(ch == '2'){
printw("You have chooese 2nd move\n\n");
    power = power2;
  }

   int damageNum =((((2*pcPoke.get_level())/5+2)*power*(pcPoke.get_atk()/wildPoke->get_def()+2))/50)*crit;
   damageNum = rand()%6+1;
  printw("Booom !!, you have deal damage amount : %d to enemy Pokemon\n", damageNum);
  wildPoke->cur_hp = wildPoke->cur_hp - damageNum;
  
  
  if(wildPoke->cur_hp < 0){
     wildPoke->cur_hp= 0;
  }
  //wildPoke->cur_hp = opHp;
  printw("Now enemy Poke pokeHp  : %d\n",wildPoke->cur_hp);
   if(wildPoke->cur_hp <=0){
    wildPoke->isDead = true;
   printw("\n                 You win\n");
   printw("click anything return");
   getch();
    return true;
}
  getch();
 return false;
}

void io_init_terminal(void)
{
  initscr();
  raw();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  start_color();
  init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
  init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
  init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
  init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
  init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
}

void io_reset_terminal(void)
{
  endwin();

  while (io_head) {
    io_tail = io_head;
    io_head = io_head->next;
    free(io_tail);
  }
  io_tail = NULL;
}

void io_queue_message(const char *format, ...)
{
  io_message_t *tmp;
  va_list ap;

  if (!(tmp = (io_message_t *) malloc(sizeof (*tmp)))) {
    perror("malloc");
    exit(1);
  }

  tmp->next = NULL;

  va_start(ap, format);

  vsnprintf(tmp->msg, sizeof (tmp->msg), format, ap);

  va_end(ap);

  if (!io_head) {
    io_head = io_tail = tmp;
  } else {
    io_tail->next = tmp;
    io_tail = tmp;
  }
}

static void io_print_message_queue(uint32_t y, uint32_t x)
{
  while (io_head) {
    io_tail = io_head;
    attron(COLOR_PAIR(COLOR_CYAN));
    mvprintw(y, x, "%-80s", io_head->msg);
    attroff(COLOR_PAIR(COLOR_CYAN));
    io_head = io_head->next;
    if (io_head) {
      attron(COLOR_PAIR(COLOR_CYAN));
      mvprintw(y, x + 70, "%10s", " --more-- ");
      attroff(COLOR_PAIR(COLOR_CYAN));
      refresh();
      getch();
    }
    free(io_tail);
  }
  io_tail = NULL;
}

/**************************************************************************
 * Compares trainer distances from the PC according to the rival distance *
 * map.  This gives the approximate distance that the PC must travel to   *
 * get to the trainer (doesn't account for crossing buildings).  This is  *
 * not the distance from the NPC to the PC unless the NPC is a rival.     *
 *                                                                        *
 * Not a bug.                                                             *
 **************************************************************************/
static int compare_trainer_distance(const void *v1, const void *v2)
{
  const Character *const *c1 = (const Character *const *) v1;
  const Character *const *c2 = (const Character *const *) v2;

  return (world.rival_dist[(*c1)->pos[dim_y]][(*c1)->pos[dim_x]] -
          world.rival_dist[(*c2)->pos[dim_y]][(*c2)->pos[dim_x]]);
}

static Character *io_nearest_visible_trainer()
{
  Character **c, *n;
  uint32_t x, y, count;

  c = (Character **) malloc(world.cur_map->num_trainers * sizeof (*c));

  /* Get a linear list of trainers */
  for (count = 0, y = 1; y < MAP_Y - 1; y++) {
    for (x = 1; x < MAP_X - 1; x++) {
      if (world.cur_map->cmap[y][x] && world.cur_map->cmap[y][x] !=
          &world.pc) {
        c[count++] = world.cur_map->cmap[y][x];
      }
    }
  }

  /* Sort it by distance from PC */
  qsort(c, count, sizeof (*c), compare_trainer_distance);

  n = c[0];

  free(c);

  return n;
}

void io_display()
{
  uint32_t y, x;
  Character *c;

//------------------------------------------------------------------
  clear();
  for (y = 0; y < MAP_Y; y++) {
    for (x = 0; x < MAP_X; x++) {
      if (world.cur_map->cmap[y][x]) {
        mvaddch(y + 1, x, world.cur_map->cmap[y][x]->symbol);
      } else {
        switch (world.cur_map->map[y][x]) {
        case ter_boulder:
          attron(COLOR_PAIR(COLOR_MAGENTA));
          mvaddch(y + 1, x, BOULDER_SYMBOL);
          attroff(COLOR_PAIR(COLOR_MAGENTA));
          break;
        case ter_mountain:
          attron(COLOR_PAIR(COLOR_MAGENTA));
          mvaddch(y + 1, x, MOUNTAIN_SYMBOL);
          attroff(COLOR_PAIR(COLOR_MAGENTA));
          break;
        case ter_tree:
          attron(COLOR_PAIR(COLOR_GREEN));
          mvaddch(y + 1, x, TREE_SYMBOL);
          attroff(COLOR_PAIR(COLOR_GREEN));
          break;
        case ter_forest:
          attron(COLOR_PAIR(COLOR_GREEN));
          mvaddch(y + 1, x, FOREST_SYMBOL);
          attroff(COLOR_PAIR(COLOR_GREEN));
          break;
        case ter_path:
          attron(COLOR_PAIR(COLOR_YELLOW));
          mvaddch(y + 1, x, PATH_SYMBOL);
          attroff(COLOR_PAIR(COLOR_YELLOW));
          break;
        case ter_gate:
          attron(COLOR_PAIR(COLOR_YELLOW));
          mvaddch(y + 1, x, GATE_SYMBOL);
          attroff(COLOR_PAIR(COLOR_YELLOW));
          break;
        case ter_bailey:
          attron(COLOR_PAIR(COLOR_YELLOW));
          mvaddch(y + 1, x, BAILEY_SYMBOL);
          attroff(COLOR_PAIR(COLOR_YELLOW));
          break;
        case ter_mart:
          attron(COLOR_PAIR(COLOR_BLUE));
          mvaddch(y + 1, x, POKEMART_SYMBOL);
          attroff(COLOR_PAIR(COLOR_BLUE));
          break;
        case ter_center:
          attron(COLOR_PAIR(COLOR_RED));
          mvaddch(y + 1, x, POKEMON_CENTER_SYMBOL);
          attroff(COLOR_PAIR(COLOR_RED));
          break;
        case ter_grass:
          attron(COLOR_PAIR(COLOR_GREEN));
          mvaddch(y + 1, x, TALL_GRASS_SYMBOL);
          attroff(COLOR_PAIR(COLOR_GREEN));
          break;
        case ter_clearing:
          attron(COLOR_PAIR(COLOR_GREEN));
          mvaddch(y + 1, x, SHORT_GRASS_SYMBOL);
          attroff(COLOR_PAIR(COLOR_GREEN));
          break;
        case ter_water:
          attron(COLOR_PAIR(COLOR_CYAN));
          mvaddch(y + 1, x, WATER_SYMBOL);
          attroff(COLOR_PAIR(COLOR_CYAN));
          break;
        default:
          attron(COLOR_PAIR(COLOR_CYAN));
          mvaddch(y + 1, x, ERROR_SYMBOL);
          attroff(COLOR_PAIR(COLOR_CYAN)); 
       }
      }
    }
  }
//---------------------------------------------------------------//


//   clear();
//   for (y = 0; y < MAP_Y; y++) {
//     for (x = 0; x < MAP_X; x++) {
//       if (world.cur_map->cmap[y][x]) {
//         mvaddch(y + 1, x, world.cur_map->cmap[y][x]->symbol);
//       } else {
//         switch (world.cur_map->map[y][x]) {
//         case ter_boulder:
//         case ter_mountain:
//           attron(COLOR_PAIR(COLOR_MAGENTA));
//           mvaddch(y + 1, x, '%');
//           attroff(COLOR_PAIR(COLOR_MAGENTA));
//           break;
//         case ter_tree:
//         case ter_forest:
//           attron(COLOR_PAIR(COLOR_GREEN));
//           mvaddch(y + 1, x, '^');
//           attroff(COLOR_PAIR(COLOR_GREEN));
//           break;
//         case ter_path:
//         case ter_gate:
//           attron(COLOR_PAIR(COLOR_YELLOW));
//           mvaddch(y + 1, x, '#');
//           attroff(COLOR_PAIR(COLOR_YELLOW));
//           break;
//         case ter_mart:
//           attron(COLOR_PAIR(COLOR_BLUE));
//           mvaddch(y + 1, x, 'M');
//           attroff(COLOR_PAIR(COLOR_BLUE));
//           break;
//         case ter_center:
//           attron(COLOR_PAIR(COLOR_RED));
//           mvaddch(y + 1, x, 'C');
//           attroff(COLOR_PAIR(COLOR_RED));
//           break;
//         case ter_grass:
//           attron(COLOR_PAIR(COLOR_GREEN));
//           mvaddch(y + 1, x, ':');
//           attroff(COLOR_PAIR(COLOR_GREEN));
//           break;
//         case ter_clearing:
//           attron(COLOR_PAIR(COLOR_GREEN));
//           mvaddch(y + 1, x, '.');
//           attroff(COLOR_PAIR(COLOR_GREEN));
//           break;
//         default:
//  /* Use zero as an error symbol, since it stands out somewhat, and it's *
//   * not otherwise used.                                                 */
//           attron(COLOR_PAIR(COLOR_CYAN));
//           mvaddch(y + 1, x, '0');
//           attroff(COLOR_PAIR(COLOR_CYAN)); 
//        }
//       }
//     }
//   }

  mvprintw(23, 1, "PC position is (%2d,%2d) on map %d%cx%d%c.",
           world.pc.pos[dim_x],
           world.pc.pos[dim_y],
           abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_x] - (WORLD_SIZE / 2) >= 0 ? 'E' : 'W',
           abs(world.cur_idx[dim_y] - (WORLD_SIZE / 2)),
           world.cur_idx[dim_y] - (WORLD_SIZE / 2) <= 0 ? 'N' : 'S');
  mvprintw(22, 1, "%d known %s.", world.cur_map->num_trainers,
           world.cur_map->num_trainers > 1 ? "trainers" : "trainer");
  mvprintw(22, 30, "Nearest visible trainer: ");
  if ((c = io_nearest_visible_trainer())) {
    attron(COLOR_PAIR(COLOR_RED));
    mvprintw(22, 55, "%c at %d %c by %d %c.",
             c->symbol,
             abs(c->pos[dim_y] - world.pc.pos[dim_y]),
             ((c->pos[dim_y] - world.pc.pos[dim_y]) <= 0 ?
              'N' : 'S'),
             abs(c->pos[dim_x] - world.pc.pos[dim_x]),
             ((c->pos[dim_x] - world.pc.pos[dim_x]) <= 0 ?
              'W' : 'E'));
    attroff(COLOR_PAIR(COLOR_RED));
  } else {
    attron(COLOR_PAIR(COLOR_BLUE));
    mvprintw(22, 55, "NONE.");
    attroff(COLOR_PAIR(COLOR_BLUE));
  }

  io_print_message_queue(0, 0);

  refresh();
}

uint32_t io_teleport_pc(pair_t dest)
{
  /* Just for fun. And debugging.  Mostly debugging. */

  do {
    dest[dim_x] = rand_range(1, MAP_X - 2);
    dest[dim_y] = rand_range(1, MAP_Y - 2);
  } while (world.cur_map->cmap[dest[dim_y]][dest[dim_x]]                  ||
           move_cost[char_pc][world.cur_map->map[dest[dim_y]]
                                                [dest[dim_x]]] == DIJKSTRA_PATH_MAX ||
           world.rival_dist[dest[dim_y]][dest[dim_x]] < 0);

  return 0;
}

static void io_scroll_trainer_list(char (*s)[40], uint32_t count)
{
  uint32_t offset;
  uint32_t i;

  offset = 0;

  while (1) {
    for (i = 0; i < 13; i++) {
      mvprintw(i + 6, 19, " %-40s ", s[i + offset]);
    }
    switch (getch()) {
    case KEY_UP:
      if (offset) {
        offset--;
      }
      break;
    case KEY_DOWN:
      if (offset < (count - 13)) {
        offset++;
      }
      break;
    case 27:
      return;
    }

  }
}

static void io_list_trainers_display(Npc **c,
                                     uint32_t count)
{
  uint32_t i;
  char (*s)[40]; /* pointer to array of 40 char */

  s = (char (*)[40]) malloc(count * sizeof (*s));

  mvprintw(3, 19, " %-40s ", "");
  /* Borrow the first element of our array for this string: */
  snprintf(s[0], 40, "You know of %d trainers:", count);
  mvprintw(4, 19, " %-40s ", s[0]);
  mvprintw(5, 19, " %-40s ", "");

  for (i = 0; i < count; i++) {
    snprintf(s[i], 40, "%16s %c: %2d %s by %2d %s",
             char_type_name[c[i]->ctype],
             c[i]->symbol,
             abs(c[i]->pos[dim_y] - world.pc.pos[dim_y]),
             ((c[i]->pos[dim_y] - world.pc.pos[dim_y]) <= 0 ?
              "North" : "South"),
             abs(c[i]->pos[dim_x] - world.pc.pos[dim_x]),
             ((c[i]->pos[dim_x] - world.pc.pos[dim_x]) <= 0 ?
              "West" : "East"));
    if (count <= 13) {
      /* Handle the non-scrolling case right here. *
       * Scrolling in another function.            */
      mvprintw(i + 6, 19, " %-40s ", s[i]);
    }
  }

  if (count <= 13) {
    mvprintw(count + 6, 19, " %-40s ", "");
    mvprintw(count + 7, 19, " %-40s ", "Hit escape to continue.");
    while (getch() != 27 /* escape */)
      ;
  } else {
    mvprintw(19, 19, " %-40s ", "");
    mvprintw(20, 19, " %-40s ",
             "Arrows to scroll, escape to continue.");
    io_scroll_trainer_list(s, count);
  }

  free(s);
}

static void io_list_trainers()
{
  Character **c;
  uint32_t x, y, count;

  c = (Character **) malloc(world.cur_map->num_trainers * sizeof (*c));

  /* Get a linear list of trainers */
  for (count = 0, y = 1; y < MAP_Y - 1; y++) {
    for (x = 1; x < MAP_X - 1; x++) {
      if (world.cur_map->cmap[y][x] && world.cur_map->cmap[y][x] !=
          &world.pc) {
        c[count++] = world.cur_map->cmap[y][x];
      }
    }
  }

  /* Sort it by distance from PC */
  qsort(c, count, sizeof (*c), compare_trainer_distance);

  /* Display it */
  io_list_trainers_display((Npc **)(c), count);
  free(c);

  /* And redraw the map */
  io_display();
}

void io_pokemart()
{
  mvprintw(0, 0, "Welcome to the Pokemart.  Could I interest you in some Pokeballs?");
  refresh();
  getch();
}

void io_pokemon_center()
{
  long unsigned int i;
  for(i = 0; i< player_pokes.size(); i ++)
  {
    if(player_pokes[i].isDead == true)
    {
      player_pokes[i].isDead = false;
    }

    player_pokes[i].cur_hp = player_pokes[i].get_hp();
  }

  mvprintw(0, 0, "Welcome to the Pokemon Center.  How can Nurse Joy assist you? Now Your Pokemon pokeHp  : %d\n",player_pokes[0].cur_hp);
  refresh();
  getch();


  //printw("Now Your Pokemon pokeHp  : %d\n",player_pokes[0].cur_hp);
}

void npcPokeInfo(Npc *npc){
  printw("this Npc have %d pokemon\n", npc->Npc_pokes.size());
  int i;
  for(i = 0;i < (int)npc->Npc_pokes.size() ; i ++){
    printw("number:%d pokemon infomation:\n", i+1);

    printw("%s%s%s: HP:%d   ATK:%d   DEF:%d   SPATK:%d   SPDEF:%d   SPEED:%d %s",
                   npc->Npc_pokes[i].is_shiny() ? "*" : "", npc->Npc_pokes[i].get_species(),
                   npc->Npc_pokes[i].is_shiny() ? "*" : "", npc->Npc_pokes[i].get_hp(), npc->Npc_pokes[i].get_atk(),
                   npc->Npc_pokes[i].get_def(), npc->Npc_pokes[i].get_spatk(), npc->Npc_pokes[i].get_spdef(),
                   npc->Npc_pokes[i].get_speed(), npc->Npc_pokes[i].get_gender_string());
  printw("\n");

  printw("%s's moves: %s   moves: %s", npc->Npc_pokes[i].get_species(),
                   npc->Npc_pokes[i].get_move(0), npc->Npc_pokes[i].get_move(1));
printw("\n");
printw("\n");
  }
}

void npcChangePokemon(vector<Pokemon> *npc_pokemons){
  long unsigned i=0;
  for(i=1; i< (*npc_pokemons).size();i++){
    if((*npc_pokemons)[i].isDead == false){
      Pokemon temp = (*npc_pokemons)[0];
      (*npc_pokemons)[0] = (*npc_pokemons)[i];
      (*npc_pokemons)[i] = temp;
      return;
    }
  }
}

bool npcturn(Pokemon pcPokemon, Pokemon *npcPokemon,vector<Pokemon> *npc_pokemons){
  printw("Now its is rival's turn\n");
  int x = rand()%4+1; 
  if(x == 1){
    attackby(&player_pokes[0], npcPokemon, npcPokemon->get_power(0));
  }else if(x == 2){ 
    attackby(&player_pokes[0], npcPokemon, npcPokemon->get_power(1));
  }else if(x == 3){ 
    printw("NPC choose to flee away, ");
   if(run(npcPokemon) == true){
     printw("NPC escape success,click anything to return");
     return true;
   } else{
     printw("NPC escape failed, now its your turn.\n");
     return false;
   }

  }else if(x == 4){
    printw("NPC changed his inital pokemon");
    npcChangePokemon(npc_pokemons);
  }
 return false;
}
bool Attackpc(vector<Pokemon> *npc_pokemons){
  
  int power1 = player_pokes[0].get_power(0);
  int power2 = player_pokes[0].get_power(1);
  int power;
  int pcSpeed = player_pokes[0].get_speed();
  int x = rand()%256;
  int crit;
  
  if(x <= pcSpeed/2){
    crit = player_pokes[0].get_atk() * 1.5;
  }else{
    crit = player_pokes[0].get_atk();
  }
  printw("\n");
  printw("\n");
  // Pokemon *p = &((*npc_pokemons)[0]);
  battleInfo(player_pokes[0],(*npc_pokemons)[0]);
  movesInfo(player_pokes[0]);
  char ch = getch();
  if(ch == '1'){
printw("You have chooese 1st move\n\n");
    power = power1;
  }else if(ch == '2'){
printw("You have chooese 2nd move\n\n");
    power = power2;
  }
   int damageNum =((((2*player_pokes[0].get_level())/5+2)*power*(player_pokes[0].get_atk()/(*npc_pokemons)[0].get_def()+2))/50)*crit;
    damageNum = rand()%6+1;
  printw("Booom !!, you have deal damage amount : %d to enemy Pokemon\n", damageNum);
  (*npc_pokemons)[0].cur_hp = (*npc_pokemons)[0].cur_hp - damageNum;
  if((*npc_pokemons)[0].cur_hp< 0){
    printw("Now enemy Poke: 0\n"); 
  }else{
  printw("Now enemy Poke: %d\n", (*npc_pokemons)[0].cur_hp); 
  }
  long unsigned i;
  int num = 0;
  if((*npc_pokemons)[0].cur_hp <= 0){
     (*npc_pokemons)[0].cur_hp= 0;
     (*npc_pokemons)[0].isDead = true;
    for(i=0; i < (*npc_pokemons).size();i++){
    if((*npc_pokemons)[i].isDead == false){
     num++;
    }
  }
     if(num > 0 ){
       printw("%s%s%s is ran out of hp, and",(*npc_pokemons)[0].is_shiny() ? "*" : "",  (*npc_pokemons)[0].get_species(),
                   (*npc_pokemons)[0].is_shiny() ? "*" : "");
       npcChangePokemon(npc_pokemons);
       printw("your opponent summon %s%s%s to the field\n",(*npc_pokemons)[0].is_shiny() ? "*" : "",  (*npc_pokemons)[0].get_species(),
                   (*npc_pokemons)[0].is_shiny() ? "*" : "");
     }else{
       printw("Your rival ran out of Pokemon\n");
       printw("You win\n");
      printw("click anything return");
       getch();
       return true;
     }
  }
  return false;
}

void npcBag(){
  clear();
  printw("1.Revive       2. Potions \n");
  char ch=getch();
  if(ch =='1'){
   revives();
  }else if(ch == '2'){
   potions();
  }
}
void io_battle(Character *aggressor, Character *defender)
{
  Npc *npc;
  int i;
  std::string s;
  
  if (!(npc = dynamic_cast<Npc *>(aggressor))) {
    npc = dynamic_cast<Npc *>(defender);
  }

//-----------------------------------------------------------------
if (!npc->buddy[1]) {
    s = "My pokemon is " + std::string(npc->buddy[0]->get_species());
  } else {
    s = "My pokemon are " + std::string(npc->buddy[0]->get_species());
  }

  for (i = 1; i < 6 && npc->buddy[i]; i++) {
    s += ", ";
    if (i == 4 || !npc->buddy[i + 1]) {
      s += "and ";
    }
    s += npc->buddy[i]->get_species();
  }
    
  s += ".";

  io_queue_message("%s", s.c_str());
//--------------------------------------------------------------//

  //io_display();
  mvprintw(0, 0, " Trainner %c wants to battle (Battle triggered)",npc->symbol);
  refresh();
  getch();

  npc->defeated = 1;
  if (npc->ctype == char_hiker || npc->ctype == char_rival) {
    npc->mtype = move_wander;
  }
  clear();
  npcPokeInfo(npc);
  
  api();
   bool endbattle = false;
  while(1){
     if(endbattle == true){
      return;
     }
     char ch=getch();  
    if(ch =='1'){
      endbattle = Attackpc(&(npc->Npc_pokes));
      if(endbattle == true){
      return;
     }
      endbattle = npcturn(player_pokes[0],&npc->Npc_pokes[0],&npc->Npc_pokes);
      api();
    }else if(ch =='2'){
      npcBag();
   endbattle = npcturn(player_pokes[0],&npc->Npc_pokes[0],&npc->Npc_pokes);
   api();
    }else if(ch == '3'){
       endbattle = run( &npc->Npc_pokes[0]);
       if(endbattle == true){
      return;
     }
       endbattle = npcturn(player_pokes[0],&npc->Npc_pokes[0],&npc->Npc_pokes);
       api();
    }else if(ch == '4'){

      ChangePokemon();
      endbattle = npcturn(player_pokes[0],&npc->Npc_pokes[0],&npc->Npc_pokes);
      api();
    }else{

    }
  }
 getch();
}

uint32_t move_pc_dir(uint32_t input, pair_t dest)
{
  dest[dim_y] = world.pc.pos[dim_y];
  dest[dim_x] = world.pc.pos[dim_x];

  switch (input) {
  case 1:
  case 2:
  case 3:
    dest[dim_y]++;
    break;
  case 4:
  case 5:
  case 6:
    break;
  case 7:
  case 8:
  case 9:
    dest[dim_y]--;
    break;
  }
  switch (input) {
  case 1:
  case 4:
  case 7:
    dest[dim_x]--;
    break;
  case 2:
  case 5:
  case 8:
    break;
  case 3:
  case 6:
  case 9:
    dest[dim_x]++;
    break;
  case '>':
    if (world.cur_map->map[world.pc.pos[dim_y]][world.pc.pos[dim_x]] ==
        ter_mart) {
      io_pokemart();
    }
    if (world.cur_map->map[world.pc.pos[dim_y]][world.pc.pos[dim_x]] ==
        ter_center) {
      io_pokemon_center();
    }
    break;
  }

  if ((world.cur_map->map[dest[dim_y]][dest[dim_x]] == ter_gate) &&
      (input == 1 || input == 3 || input == 7 || input == 9)) {
    return 1;
  }

  if (world.cur_map->cmap[dest[dim_y]][dest[dim_x]]) {
    if (dynamic_cast<Npc *>(world.cur_map->cmap[dest[dim_y]][dest[dim_x]]) &&
        ((Npc *) world.cur_map->cmap[dest[dim_y]][dest[dim_x]])->defeated) {
      // Some kind of greeting here would be nice
      return 1;
    } else if (dynamic_cast<Npc *>
               (world.cur_map->cmap[dest[dim_y]][dest[dim_x]])) {
      io_battle(&world.pc, world.cur_map->cmap[dest[dim_y]][dest[dim_x]]);
      // Not actually moving, so set dest back to PC position
      dest[dim_x] = world.pc.pos[dim_x];
      dest[dim_y] = world.pc.pos[dim_y];
    }
  }
  
  if (move_cost[char_pc][world.cur_map->map[dest[dim_y]][dest[dim_x]]] ==
      DIJKSTRA_PATH_MAX) {
    return 1;
  }

  //-----------------------------------------------------------------
  if (world.cur_map->map[dest[dim_y]][dest[dim_x]] == ter_gate &&
      dest[dim_y] != world.pc.pos[dim_y]                       &&
      dest[dim_x] != world.pc.pos[dim_x]) {
    return 1;
  }
  //-------------------------------------------------------------//

  return 0;
}

void io_teleport_world(pair_t dest)
{
  int x = INT_MAX, y = INT_MAX;
  
  world.cur_map->cmap[world.pc.pos[dim_y]][world.pc.pos[dim_x]] = NULL;

  mvprintw(0, 0, "Enter x [-200, 200]: ");
  refresh();
  echo();
  curs_set(1);
  mvscanw(0, 21, (char *) "%d", &x);
  mvprintw(0, 0, "Enter y [-200, 200]:          ");
  refresh();
  mvscanw(0, 21, (char *) "%d", &y);
  refresh();
  noecho();
  curs_set(0);

  if (x < -200) {
    x = -200;
  }
  if (x > 200) {
    x = 200;
  }
  if (y < -200) {
    y = -200;
  }
  if (y > 200) {
    y = 200;
  }
  
  x += 200;
  y += 200;

  world.cur_idx[dim_x] = x;
  world.cur_idx[dim_y] = y;

  new_map(1);
  io_teleport_pc(dest);
}

bool Pokeball(Pokemon *wildPoke){
  printw("Throwing Poke Ball to %s%s%s\n", wildPoke->is_shiny() ? "*" : "", wildPoke->get_species(),
                   wildPoke->is_shiny() ? "*" : "");
  int size = player_pokes.size();

  printw("You have %d Pokemon / Pokemons in your bag\n", size);
  if(size ==6 ){
    printw("You cannot Capture this pokemon because there is no room for this pokemon\n");
    return false;
  }else{
    player_pokes.push_back(*wildPoke);
    printw("Successfully Captured !\n");
    printw("A %s%s%s is adding to your Bag \n", wildPoke->is_shiny() ? "*" : "", wildPoke->get_species(),
                   wildPoke->is_shiny() ? "*" : "");
  }

  printw("There are %d pokemons in your bag", player_pokes.size());
  getch();
  return true;
}
bool histurn(Pokemon pcPoke, Pokemon *wildPoke){
  int x = rand()%3+1;
 bool isEnd;
  if(x == 1){
    // attack
    printw("opponent pokemon move1");
    isEnd = attackby(&pcPoke, wildPoke, wildPoke->get_power(0));
    if(isEnd == true){
      return isEnd;
    }
  }else if(x ==2 ){
     printw("opponent pokemon move2");
    isEnd = attackby(&pcPoke, wildPoke, wildPoke->get_power(1));
    if(isEnd == true){
      return isEnd;
    }
  }else if(x ==3 ){
     printw("opponent pokemon escape");
     getch();
    return true;
  }
  return false;

}
bool Bag(Pokemon pcPoke,Pokemon *p){
  clear();
  bool isEnd =false;
  printw("1.Revive       2. Potions      3.Pokeball(Capture)\n");
  char ch=getch();
  if(ch =='1'){
   revives();
  }else if(ch == '2'){
   potions();
  }else if(ch == '3'){
    clear();
     isEnd = Pokeball(p);
  }
  return isEnd;
}
void wildePokeBattle(vector<Pokemon> pc_pokemon, Pokemon *p){  
  api();
 
   bool endbattle = false;
  while(1){
     if(endbattle == true){
      return;
     }
     char ch=getch();  
    if(ch =='1'){
      endbattle = Attack(pc_pokemon[0],p);
      if(endbattle == true){
      return;
     }
      endbattle = histurn(pc_pokemon[0],p);
      api();
    }else if(ch == '2'){
     endbattle =  Bag(pc_pokemon[0],p);
     if(endbattle == true){
      return;
     }
     endbattle = histurn(pc_pokemon[0],p);
    }else if(ch =='3'){
      endbattle = run(p);
      if(endbattle == true){
      return;
     }
     endbattle = histurn(pc_pokemon[0],p);
     api();
    }else if(ch =='4'){
      ChangePokemon();
      endbattle = histurn(pc_pokemon[0],p);
      api();
    }else if(ch =='q'){
      break;
    }else {
      
      printw("wrong input");
    }
   
  }
}
void io_encounter_pokemon()
{
  Pokemon *p;
  
  int md = (abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)) +
            abs(world.cur_idx[dim_x] - (WORLD_SIZE / 2)));
  int minl, maxl;
  
  if (md <= 200) {
    minl = 1;
    maxl = md / 2;
  } else {
    minl = (md - 200) / 2;
    maxl = 100;
  }
  if (minl < 1) {
    minl = 1;
  }
  if (minl > 100) {
    minl = 100;
  }
  if (maxl < 1) {
    maxl = 1;
  }
  if (maxl > 100) {
    maxl = 100;
  }

  level =rand() % (maxl - minl + 1) + minl; 
  p = new Pokemon(level);
  p->isDead = false;
  //  std::cerr << *p << std::endl << std::endl;
  clear();
  printw("%s%s%s: HP:%d   ATK:%d   DEF:%d   SPATK:%d   SPDEF:%d   SPEED:%d %s",
                   p->is_shiny() ? "*" : "", p->get_species(),
                   p->is_shiny() ? "*" : "", p->get_hp(), p->get_atk(),
                   p->get_def(), p->get_spatk(), p->get_spdef(),
                   p->get_speed(), p->get_gender_string());
  printw("\n");

  printw("%s's moves: %s   moves: %s", p->get_species(),
                   p->get_move(0), p->get_move(1));
refresh();
 pcHp = player_pokes[0].get_hp();
 pcHp1 = player_pokes[0].get_hp();
  opHp = p->cur_hp= p->get_hp();
  opHp1 = p->cur_hp= p->get_hp();
 wildePokeBattle(player_pokes, p);
}

void io_handle_input(pair_t dest)
{
  uint32_t turn_not_consumed;
  int key;
  char ch;
  // Pokemon pc_pokemon;
  // Pokemon *p;
  //bool b = true;


  do {
    switch (key = getch()) {
    case '7':
    case 'y':
    case KEY_HOME:
      turn_not_consumed = move_pc_dir(7, dest);
      break;
    case '8':
    case 'k':
    case KEY_UP:
      turn_not_consumed = move_pc_dir(8, dest);
      break;
    case '9':
    case 'u':
    case KEY_PPAGE:
      turn_not_consumed = move_pc_dir(9, dest);
      break;
    case '6':
    case 'l':
    case KEY_RIGHT:
      turn_not_consumed = move_pc_dir(6, dest);
      break;
    case '3':
    case 'n':
    case KEY_NPAGE:
      turn_not_consumed = move_pc_dir(3, dest);
      break;
    case '2':
    case 'j':
    case KEY_DOWN:
      turn_not_consumed = move_pc_dir(2, dest);
      break;
    case '1':
    case 'b':
    case KEY_END:
      turn_not_consumed = move_pc_dir(1, dest);
      break;
    case '4':
    case 'h':
    case KEY_LEFT:
      turn_not_consumed = move_pc_dir(4, dest);
      break;
    case '5':
    case ' ':
    case '.':
    case KEY_B2:
      dest[dim_y] = world.pc.pos[dim_y];
      dest[dim_x] = world.pc.pos[dim_x];
      turn_not_consumed = 0;
      break;
    case '>':
      turn_not_consumed = move_pc_dir('>', dest);
      break;
    case 'B':
      printw("1.Revive       2. Potions\n");
      ch=getch();
      if(ch =='1'){
      revives();
      }else if(ch == '2'){
      potions();
      }
      turn_not_consumed = 0;
      break;
    case 'Q':
      dest[dim_y] = world.pc.pos[dim_y];
      dest[dim_x] = world.pc.pos[dim_x];
      world.quit = 1;
      turn_not_consumed = 0;
      break;
      break;
    case 'p':
      /* Teleport the PC to a random place in the map.              */
      io_teleport_pc(dest);
      turn_not_consumed = 0;
      break;
    case 'f':
      /* Teleport the PC to any map in the world.                   */
      io_teleport_world(dest);
      turn_not_consumed = 0;
      break;
    case 't':
      io_list_trainers();
      turn_not_consumed = 1;
      break;
    case 'q':
      /* Demonstrate use of the message queue.  You can use this for *
       * printf()-style debugging (though gdb is probably a better   *
       * option.  Not that it matters, but using this command will   *
       * waste a turn.  Set turn_not_consumed to 1 and you should be *
       * able to figure out why I did it that way.                   */
      io_queue_message("This is the first message.");
      io_queue_message("Since there are multiple messages, "
                       "you will see \"more\" prompts.");
      io_queue_message("You can use any key to advance through messages.");
      io_queue_message("Normal gameplay will not resume until the queue "
                       "is empty.");
      io_queue_message("Long lines will be truncated, not wrapped.");
      io_queue_message("io_queue_message() is variadic and handles "
                       "all printf() conversion specifiers.");
      io_queue_message("Did you see %s?", "what I did there");
      io_queue_message("When the last message is displayed, there will "
                       "be no \"more\" prompt.");
      io_queue_message("Have fun!  And happy printing!");
      io_queue_message("Oh!  And use 'Q' to quit!");

      dest[dim_y] = world.pc.pos[dim_y];
      dest[dim_x] = world.pc.pos[dim_x];
      turn_not_consumed = 0;
      break;
    default:
    /* Also not in the spec.  It's not always easy to figure out what *
       * key code corresponds with a given keystroke.  Print out any    *
       * unhandled key here.  Not only does it give a visual error      *
       * indicator, but it also gives an integer value that can be used *
       * for that key in this (or other) switch statements.  Printed in *
       * octal, with the leading zero, because ncurses.h lists codes in *
       * octal, thus allowing us to do reverse lookups.  If a key has a *
       * name defined in the header, you can use the name here, else    *
       * you can directly use the octal value.                          */
      mvprintw(0, 0, "Unbound key: %#o ", key);
      turn_not_consumed = 1;
    }
    refresh();
  } while (turn_not_consumed);

    // switch(key = getch()){
    //   case 'B':
    //   printw("1.Revive       2. Potions\n");
    //   ch=getch();
    //   if(ch =='1'){
    //   revives();
    //   }else if(ch == '2'){
    //   potions();
    //   }
    //   break;
    // }
}
