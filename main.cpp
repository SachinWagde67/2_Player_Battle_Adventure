#include <bits/stdc++.h>
#include <unistd.h>
#define CLRSCR "\e[2J\e[H";
#define RED "\x1b[31m";
#define GREEN "\x1b[32m";
#define BLUE "\x1b[34m";
#define MAGENTA "\x1b[35m";
#define WHITE "\x1b[37m";
using namespace std;
int p1=0,p2=0;
int introChoice;
void intro();

class Player
{
  public:
  int health;
  int baseDmg;
  int addDmg;
  int heal;

  void setHealth(int h)
  {
    health = h;
  }
  int getHealth()
  {
    return health;
  }

  virtual int Damage() = 0;
  virtual int addDamage() = 0;
  virtual int Healing() = 0;
  virtual void takeDamage(int) = 0;
};

class Warrior : public Player
{
  public: 
  Warrior()
  {
    setHealth(400);
  }

  int Damage()
  {
    baseDmg = 10;
    return baseDmg;
  }
  int addDamage()
  {
    srand(time(NULL));
    int w = rand() % 11 + 10;
    if(w > 17)
    {
      cout<<"OHHH! A CRITICAL HIT: "<<w<<endl;
      return w;
    }
    else 
    {
      cout<<"Nice Additional Damage: "<<w<<endl;
      return w;
    }
  }
  int Healing()
  {
    srand(time(NULL));
    int h = rand() % 6 + 5;
    if(health < 400)
    {
      health += h;
      cout<<"Warrior used Healing Portion and increased his health by: "<<h<<endl;
      if(health >= 400)
      {
        health = 400;
      }
    }
    else if(health == 400)
    {
      cout<<"Can't use Health Potion! Health is already Full "<<endl;
    }
    return h;
  }
  void takeDamage(int d)
  {
    health -= d;
    if(health <= 0)
    {
      health = 0;
    }
  }
  
};

class Ninja : public Player
{
  public: 
  Ninja()
  {
    setHealth(300);
  }

  int Damage()
  {
    baseDmg = 20;
    return baseDmg;
  }
  int addDamage()
  {
    srand(time(NULL));
    int n = rand() % 11 + 5;
    if(n > 12)
    {
      cout<<"OHHH! A CRITICAL HIT: "<<n<<endl;
      return n;
    }
    else 
    {
      cout<<"Nice Additional Damage: "<<n<<endl;
      return n;
    }
  }
  int Healing()
  {
    srand(time(NULL));
    int h = rand() % 6 + 10;
    if(health < 300)
    {
      health += h;
      cout<<"Ninja used Healing Portion and increased his health by: "<<h<<endl;
      if(health >= 300)
      {
        health = 300;
      }
    }
    else if(health == 300)
    {
      cout<<"Can't use Health Potion! Health is already Full "<<endl;
    }
    return h;
  }
  void takeDamage(int d)
  {
    health -= d;
    if(health <= 0)
    {
      health = 0;
    }
  }
};

class Wizard : public Player
{
  public: 
  Wizard()
  {
    setHealth(200);
  }

  int Damage()
  {
    baseDmg = 30;
    return baseDmg;
  }
  int addDamage()
  {
    srand(time(NULL));
    int wiz = rand() % 6 + 10;
    if(wiz > 12)
    {
      cout<<"OHHH! A CRITICAL HIT: "<<wiz<<endl;
      return wiz;
    }
    else 
    {
      cout<<"Nice Additional Damage: "<<wiz<<endl;
      return wiz;
    }
  }
  int Healing()
  {
    srand(time(NULL));
    int h = rand() % 11 + 20;
    if(health < 200)
    {
      health += h;
      cout<<"Wizard used Healing Portion and increased his health by: "<<h<<endl;
      if(health >= 200)
      {
        health = 200;
      }
    }
    else if(health == 200)
    {
      cout<<"Can't use Health Potion! Health is already Full "<<endl;
    }
    return h;
  }
  void takeDamage(int d)
  {
    health -= d;
    if(health <= 0)
    {
      health = 0;
    }
  }
};

void startGame()
{
  cout << CLRSCR;
  cout<<"There are 3 types of Players in the Game"<<endl<<endl
      <<"1) Warrior ->"<<endl
      <<"   Health ->  400 "<<endl
      <<"   Base Damage -> 10 "<<endl
      <<"   Heal -> Random Between 5 - 10 "<<endl
      <<"   Additional Damage -> Random Between 10 - 20"<<endl;
  cout<<"2) Ninja ->"<<endl
      <<"   Health -> 300  "<<endl
      <<"   Base Damage -> 20 "<<endl
      <<"   Heal -> Random Between 10 - 15 "<<endl
      <<"   Additional Damage -> Random Between 5 - 15"<<endl;
  cout<<"3) Wizard -> "<<endl
      <<"   Health ->  200 "<<endl
      <<"   Base Damage -> 30 "<<endl
      <<"   Heal -> Random Between 20 - 30 "<<endl
      <<"   Additional Damage -> Random Between 10 - 15"<<endl<<endl;
  cout<< MAGENTA;
  cout<<"  NOTE - Both Players must choose different characters  "<<endl<<endl; 
  cout<< WHITE;
}

void choosedCharacter(int p)
{
  switch(p)
  {
    case 1: cout<<RED;
            cout<<"You selected WARRIOR "<<endl<<endl;
            cout<<WHITE;  
            break;
    case 2: cout<<GREEN;
            cout<<"You selected NINJA "<<endl<<endl; 
            cout<<WHITE;
            break;
    case 3: cout<<BLUE;
            cout<<"You selected WIZARD "<<endl<<endl;
            cout<<WHITE;
            break;
  }
}

void charSelect()
{
  switch(introChoice)
  {
    case 1:
    {
      bool select1 = true;
      bool select2 = true;
      char c1,c2;
      cout << CLRSCR;
      startGame();
      while(select1)
      {
        cout<<"Player1 : Choose Your Character "<<endl;
        cin>>p1;
        if(p1 == 1 || p1 == 2 || p1 == 3)
        {
          cout<<"Do you want to choose this Character? (Y/N)"<<endl;
          cin>>c1;
          if(c1 == 'Y' || c1 == 'y')
          {
            select1 = false;
            choosedCharacter(p1);
          }
          else if(c1 == 'N' || c1 == 'n')
          {
            select1 = true;
          }
        }
        else
        {
          cout<<"Invalid Input! Please select a valid character for Player 1 "<<endl;
          sleep(2);
        }
      }
      while(select2)
      {
        cout<<"Player2 : Choose Your Character "<<endl;
        cin>>p2;
        if(p2 == 1 || p2 == 2 || p2 == 3)
        {
          cout<<"Do you want to choose this Character? (Y/N)"<<endl;
          cin>>c2;
          if( p1 == p2 )
          {
            cout<<"Choose a different Character "<<endl<<endl;
            select2 = true;
          }
          else if( p1 != p2 )
          {
            if(c2 == 'Y' || c2 == 'y')
            {
              select2 = false;
              choosedCharacter(p2);
            }
            else if(c2 == 'N' || c2 == 'n')
            {
              select2 = true;
            }
          }
        }
        else if(p2 != 1 || p2 != 2 || p2 != 3)
        {
          cout<<"Invalid Input! Please select a valid character for Player 2 "<<endl;
          sleep(2);
        }
      }
      break;
    }
    
    case 2:
    {
      char back;
      cout << CLRSCR;
      cout<<"-------------------- RULES -------------------- "<<endl
          <<"1) Each Player can play only one turn at a time "<<endl
          <<"2) Both Players must select two different Characters "<<endl
          <<"3) If the health of the player reaches 0, then that player will lose and the game will end "<<endl
          <<"4) In each turn the player have two choices, either heal himself or damage the other "<<endl
          <<"5) Press H to Heal and D to deal Damage \n\n"<<endl; 
          cout<<"Press B to go to the Main Menu!!! "<<endl;
          cin>>back;
          if(back == 'B' || back == 'b')
          {
            intro();
          }
      break;
    }
    
    case 3:
    {
      char e;
      cout<<"Do you want to leave the game!!! ( Y/N )"<<endl;
      cin>>e;
      if(e == 'y' || e == 'Y')
      {
        cout<<"Game is closing"<<endl;
        sleep(2);
        exit(0);
      }
      else if(e == 'n' || e == 'N')
      {
        cout<<"Taking you back to the main menu"<<endl
            <<"Wait for some time"<<endl;
        sleep(2);
        intro();
      }
      break;
    }
    
    default:
    {
      cout<<"Please enter a valid choice!!! "<<endl<<endl
          <<"GOING BACK TO THE MAIN MENU "<<endl;
      sleep(2);
      intro();
      break;
    }
  }
}

void intro()
{
  cout << CLRSCR;
  cout<<"Please Select: "<<endl
      <<"1. Start Game "<<endl
      <<"2. Rules "<<endl
      <<"3. Exit "<<endl;
  cin>>introChoice;
  charSelect();
}

int main()
{
  char HorD;
  cout << CLRSCR;
  cout<<"Welcome to the 2-Player Battle Adventure Game!!!"<<endl<<endl<<endl
      <<"\t ( PLEASE WAIT! GAME IS LOADING....) "<<endl<<endl<<endl;
  sleep(3);
  intro();
  switch(p1)
  {
    case 1: 
    {
      Warrior w;
      switch(p2)
      {
        case 2:
        {
          Ninja n;
          while(w.getHealth() > 0 && n.getHealth() > 0)
          {
            while(w.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
            {
              cout<< RED ;
              cout<<"Warrior's Turn: "<<endl
                  <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
              cin>>HorD;
              switch(tolower(HorD))
              {
                case 'h': 
                {
                  int wh = w.Healing();
                  cout<<"Warrior's Health: "<<w.getHealth()<<endl;
                  break;
                }
                case 'd':
                {
                  srand(time(NULL));
                  if(rand() % 5 + 1 > 3)
                  {
                    int bsdmg = w.Damage();
                    int addmg = w.addDamage();
                    n.takeDamage(bsdmg + addmg);
                    cout<<"Warrior deals a damage of: "<<bsdmg + addmg<<" to Ninja! "<<endl
                        <<"Ninja's Health: "<<n.getHealth()<<endl;
                  }
                  else
                  {
                    int bsdmg = w.Damage();
                    n.takeDamage(bsdmg);
                    cout<<"Warrior deals a damage of: "<<bsdmg<<" to Ninja! "<<endl
                        <<"Ninja's Health: "<<n.getHealth()<<endl;
                  }
                  break;
                }
                default: 
                {
                  cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                  break;
                }        
              }
            }
            HorD = 'a';
            cout<<WHITE;
            cout<<"*********************************************************************************"<<endl<<endl;
            while(n.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
            {
              cout<<GREEN;
              cout<<"Ninja's Turn: "<<endl
                  <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
              cin>>HorD;
              switch(tolower(HorD))
              {
                case 'h': 
                {
                  int nh = n.Healing();
                  cout<<"Ninja's Health: "<<n.getHealth()<<endl;
                  break;
                }
                case 'd':
                {
                  srand(time(NULL));
                  if(rand() % 5 + 1 > 3)
                  {
                    int bsdmg = n.Damage();
                    int addmg = n.addDamage();
                    w.takeDamage(bsdmg + addmg);
                    cout<<"Ninja deals a damage of: "<<bsdmg + addmg<<" to Warrior! "<<endl
                        <<"Warrior's Health: "<<w.getHealth()<<endl;
                  }
                  else
                  {
                    int bsdmg = n.Damage();
                    w.takeDamage(bsdmg);
                    cout<<"Ninja deals a damage of: "<<bsdmg<<" to Warrior! "<<endl
                    <<"Warrior's Health: "<<w.getHealth()<<endl;
                  }
                break;
              }
              default: 
              {
                cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                break;
              }         
            }
          }
          HorD = 'a';
          cout<<WHITE;
          cout<<"*********************************************************************************"<<endl<<endl;
        } 
        if(w.getHealth() > n.getHealth())
        {
          cout<<"\t\t\t******************* WINNER IS WARRIOR ******************* "<<endl;
        }
        else
        {
          cout<<"\t\t\t******************** WINNER IS NINJA ******************** "<<endl;
        }
        break;
      }
      case 3:
      {
        Wizard wiz;
        while(w.getHealth() > 0 && wiz.getHealth() > 0)
        {
          while(w.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
          {
            cout<< RED ;
            cout<<"Warrior's Turn: "<<endl
                <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
            cin>>HorD;
            switch(tolower(HorD))
            {
              case 'h': 
              {
                int wh = w.Healing();
                cout<<"Warrior's Health: "<<w.getHealth()<<endl;
                break;
              }
              case 'd':
              {
                srand(time(NULL));
                if(rand() % 5 + 1 > 3)
                {
                  int bsdmg = w.Damage();
                  int addmg = w.addDamage();
                  wiz.takeDamage(bsdmg + addmg);
                  cout<<"Warrior deals a damage of: "<<bsdmg + addmg<<" to Wizard! "<<endl
                      <<"Wizard's Health: "<<wiz.getHealth()<<endl;
                }
                else
                {
                  int bsdmg = w.Damage();
                  wiz.takeDamage(bsdmg);
                  cout<<"Warrior deals a damage of: "<<bsdmg<<" to Wizard! "<<endl
                      <<"Wizard's Health: "<<wiz.getHealth()<<endl;
                }
                break;
              }
              default: 
              {
                cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                break;
              }        
            }
          } 
          HorD = 'a';
          cout<<WHITE;
          cout<<"*********************************************************************************"<<endl<<endl;
          while(wiz.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
          {
            cout<<BLUE;
            cout<<"Wizard's Turn: "<<endl
                <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
            cin>>HorD;
            switch(tolower(HorD))
            {
              case 'h': 
              {
                int nh = wiz.Healing();
                cout<<"Wizard's Health: "<<wiz.getHealth()<<endl;
                break;
              }
              case 'd':
              {
                srand(time(NULL));
                if(rand() % 5 + 1 > 3)
                {
                  int bsdmg = wiz.Damage();
                  int addmg = wiz.addDamage();
                  w.takeDamage(bsdmg + addmg);
                  cout<<"Wizard deals a damage of: "<<bsdmg + addmg<<" to Warrior! "<<endl
                      <<"Warrior's Health: "<<w.getHealth()<<endl;
                }
                else
                {
                  int bsdmg = wiz.Damage();
                  w.takeDamage(bsdmg);
                  cout<<"Wizard deals a damage of: "<<bsdmg<<" to Warrior! "<<endl
                      <<"Warrior's Health: "<<w.getHealth()<<endl;
                }
                break;
              }
              default: 
              {
                cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                break;
              }         
            }
          }
          HorD = 'a';
          cout<<WHITE;
          cout<<"*********************************************************************************"<<endl<<endl;
        }
        if(w.getHealth() > wiz.getHealth())
        {
          cout<<"\t\t\t******************* WINNER IS WARRIOR ******************* "<<endl;
        }
        else
        {
          cout<<"\t\t\t******************* WINNER IS WIZARD ******************** "<<endl;
        }
        break;
      }
      }
      break;
    }

    case 2: 
    {
      Ninja n;
      switch(p2)
      {
        case 1:
        {
          Warrior w;
          while(n.getHealth() > 0 && w.getHealth() > 0)
          {
            while(n.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
            {
              cout<< GREEN ;
              cout<<"Ninja's Turn: "<<endl
                  <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
              cin>>HorD;
              switch(tolower(HorD))
              {
                case 'h': 
                {
                  int wh = n.Healing();
                  cout<<"Ninja's Health: "<<n.getHealth()<<endl;
                  break;
                }
                case 'd':
                {
                  srand(time(NULL));
                  if(rand() % 5 + 1 > 3)
                  {
                    int bsdmg = n.Damage();
                    int addmg = n.addDamage();
                    w.takeDamage(bsdmg + addmg);
                    cout<<"Ninja deals a damage of: "<<bsdmg + addmg<<" to Warrior! "<<endl
                        <<"Warrior's Health: "<<w.getHealth()<<endl;
                  }
                  else
                  {
                    int bsdmg = n.Damage();
                    w.takeDamage(bsdmg);
                    cout<<"Ninja deals a damage of: "<<bsdmg<<" to Warrior! "<<endl
                        <<"Warrior's Health: "<<w.getHealth()<<endl;
                  }
                  break;
                }
                default: 
                {
                  cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                  break;
                }        
              }
            }
            HorD = 'a';
            cout<<WHITE;
            cout<<"*********************************************************************************"<<endl<<endl;
            while(w.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
            {
              cout<<RED;
              cout<<"Warrior's Turn: "<<endl
                  <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
              cin>>HorD;
              switch(tolower(HorD))
              {
                case 'h': 
                {
                  int nh = w.Healing();
                  cout<<"Warrior's Health: "<<w.getHealth()<<endl;
                  break;
                }
                case 'd':
                {
                  srand(time(NULL));
                  if(rand() % 5 + 1 > 3)
                  {
                    int bsdmg = w.Damage
                ();
                    int addmg = w.addDamage
                ();
                    n.takeDamage(bsdmg + addmg);
                    cout<<"Warrior deals a damage of: "<<bsdmg + addmg<<" to Ninja! "<<endl
                        <<"Ninja's Health: "<<n.getHealth()<<endl;
                  }
                  else
                  {
                    int bsdmg = w.Damage
                ();
                    n.takeDamage(bsdmg);
                    cout<<"Warrior deals a damage of: "<<bsdmg<<" to Ninja! "<<endl
                        <<"Ninja's Health: "<<n.getHealth()<<endl;
                  }
                  break;
                }
                default: 
                {
                  cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                  break;
                }         
              }
            }
            HorD = 'a';
            cout<<WHITE;
            cout<<"*********************************************************************************"<<endl<<endl;
          }
          if(n.getHealth() > w.getHealth())
          {
            cout<<"\t\t\t******************** WINNER IS NINJA ******************** "<<endl;
          }
          else
          {
            cout<<"\t\t\t******************* WINNER IS WARRIOR ******************* "<<endl;
          }
          break;
        }
        case 3:
        {
          Wizard wiz;
          while(n.getHealth() > 0 && wiz.getHealth() > 0)
          {
            while(n.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
            {
              cout<< GREEN ;
              cout<<"Ninja's Turn: "<<endl
                  <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
              cin>>HorD;
              switch(tolower(HorD))
              {
                case 'h': 
                {
                  int wh = n.Healing();
                  cout<<"Ninja's Health: "<<n.getHealth()<<endl;
                  break;
                }
                case 'd':
                {
                  srand(time(NULL));
                  if(rand() % 5 + 1 > 3)
                  {
                    int bsdmg = n.Damage();
                    int addmg = n.addDamage();
                    wiz.takeDamage(bsdmg + addmg);
                    cout<<"Ninja deals a damage of: "<<bsdmg + addmg<<" to Wizard! "<<endl
                        <<"Wizard's Health: "<<wiz.getHealth()<<endl;
                  }
                  else
                  {
                    int bsdmg = n.Damage();
                    wiz.takeDamage(bsdmg);
                    cout<<"Ninja deals a damage of: "<<bsdmg<<" to Wizard! "<<endl
                        <<"Wizard's Health: "<<wiz.getHealth()<<endl;
                  }
                  break;
                }
                default: 
                {
                  cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                  break;
                }        
              }
            }
            HorD = 'a';
            cout<<WHITE;
            cout<<"*********************************************************************************"<<endl<<endl;
            while(wiz.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
            {
              cout<<BLUE;
              cout<<"Wizard's Turn: "<<endl
                  <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
              cin>>HorD;
              switch(tolower(HorD))
              {
                case 'h': 
                {
                  int nh = wiz.Healing();
                  cout<<"Wizard's Health: "<<wiz.getHealth()<<endl;
                  break;
                }
                case 'd':
                {
                  srand(time(NULL));
                  if(rand() % 5 + 1 > 3)
                  {
                    int bsdmg = wiz.Damage();
                    int addmg = wiz.addDamage();
                    n.takeDamage(bsdmg + addmg);
                    cout<<"Wizard deals a damage of: "<<bsdmg + addmg<<" to Ninja! "<<endl
                        <<"Ninja's Health: "<<n.getHealth()<<endl;
                  }
                  else
                  {
                    int bsdmg = wiz.Damage();
                    n.takeDamage(bsdmg);
                    cout<<"Wizard deals a damage of: "<<bsdmg<<" to Ninja! "<<endl
                        <<"Ninja's Health: "<<n.getHealth()<<endl;
                  }
                  break;
                }
                default: 
                {
                  cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                  break;
                }         
              }
            }
            HorD = 'a';
            cout<<WHITE;
            cout<<"*********************************************************************************"<<endl<<endl;
          }
          if(n.getHealth() > wiz.getHealth())
          {
            cout<<"\t\t\t******************** WINNER IS NINJA ******************** "<<endl;
          }
          else
          {
            cout<<"\t\t\t******************* WINNER IS WIZARD ******************** "<<endl;
          }
          break;
        }
      }
      break;
    }

    case 3: 
    {
      Wizard wiz;
      switch(p2)
      {
        case 1:
        {
          Warrior w;
          while(wiz.getHealth() > 0 && w.getHealth() > 0)
          {
            while(wiz.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
            {
              cout<< BLUE ;
              cout<<"Wizard's Turn: "<<endl
                  <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
              cin>>HorD;
              switch(tolower(HorD))
              {
                case 'h': 
                {
                 int wh = wiz.Healing();
                 cout<<"Wizard's Health: "<<wiz.getHealth()<<endl;
                 break;
                }
               case 'd':
               {
                 srand(time(NULL));
                 if(rand() % 5 + 1 > 3)
                 {
                   int bsdmg = wiz.Damage();
                   int addmg = wiz.addDamage();
                   w.takeDamage(bsdmg + addmg);
                   cout<<"Wizard deals a damage of: "<<bsdmg + addmg<<" to Warrior! "<<endl
                       <<"Warrior's Health: "<<w.getHealth()<<endl;
                 }
                 else
                 {
                   int bsdmg = w.Damage
                ();
                   w.takeDamage(bsdmg);
                   cout<<"Wizard deals a damage of: "<<bsdmg<<" to Warrior! "<<endl
                       <<"Warrior's Health: "<<w.getHealth()<<endl;
                 }
                 break;
               }
               default: 
               {
                 cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                 break;
               }        
              }
            }
            HorD = 'a';
            cout<<WHITE;
            cout<<"*********************************************************************************"<<endl<<endl;
            while(w.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
            {
              cout<<RED;
              cout<<"Warrior's Turn: "<<endl
                <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
              cin>>HorD;
              switch(tolower(HorD))
              {
                case 'h': 
                {
                 int nh = w.Healing();
                 cout<<"Warrior's Health: "<<w.getHealth()<<endl;
                 break;
                }
                case 'd':
                {
                  srand(time(NULL));
                  if(rand() % 5 + 1 > 3)
                  {
                    int bsdmg = w.Damage
                ();
                    int addmg = w.addDamage
                ();
                    wiz.takeDamage(bsdmg + addmg);
                    cout<<"Warrior deals a damage of: "<<bsdmg + addmg<<" to Wizard! "<<endl
                        <<"Wizard's Health: "<<wiz.getHealth()<<endl;
                  }
                  else
                  {
                    int bsdmg = w.Damage
                ();
                    wiz.takeDamage(bsdmg);
                    cout<<"Warrior deals a damage of: "<<bsdmg<<" to Wizard! "<<endl
                        <<"Wizard's Health: "<<wiz.getHealth()<<endl;
                  }
                  break;
                }
                default: 
                {
                  cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                  break;
                }         
              }
            }
            HorD = 'a';
            cout<<WHITE;
            cout<<"*********************************************************************************"<<endl<<endl;
          } 
          if(w.getHealth() > wiz.getHealth())
          {
            cout<<"\t\t\t******************* WINNER IS WARRIOR ******************* "<<endl;
          }
          else
          {
            cout<<"\t\t\t******************* WINNER IS WIZARD ******************** "<<endl;
          }
          break;
        }
        case 2:
        {
          Ninja n;
          while(wiz.getHealth() > 0 && n.getHealth() > 0)
          {
            while(wiz.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
            {
              cout<< BLUE ;
              cout<<"Wizard's Turn: "<<endl
                  <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
              cin>>HorD;
              switch(tolower(HorD))
              {
                case 'h': 
                {
                 int wh = wiz.Healing();
                 cout<<"Wizard's Health: "<<wiz.getHealth()<<endl;
                 break;
                }
                case 'd':
                {
                  srand(time(NULL));
                  if(rand() % 5 + 1 > 3)
                  {
                    int bsdmg = wiz.Damage();
                    int addmg = wiz.addDamage();
                    n.takeDamage(bsdmg + addmg);
                    cout<<"Wizard deals a damage of: "<<bsdmg + addmg<<" to Ninja! "<<endl
                        <<"Ninja's Health: "<<n.getHealth()<<endl;
                  }
                  else
                  {
                    int bsdmg = wiz.Damage();
                    n.takeDamage(bsdmg);
                    cout<<"Wizard deals a damage of: "<<bsdmg<<" to Ninja! "<<endl
                        <<"Ninja's Health: "<<n.getHealth()<<endl;
                  }
                  break;
                }
                default: 
                {
                  cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                  break;
                }        
              }
            }
            HorD = 'a';
            cout<<WHITE;
            cout<<"*********************************************************************************"<<endl<<endl;
            while(n.getHealth()>0 && (tolower(HorD) != 'h' && tolower(HorD) != 'd'))
            {
              cout<< GREEN ;
              cout<<"Ninja's Turn: "<<endl
                <<"Press H to use Healing Potion or D to Damage the opponent "<<endl;
              cin>>HorD;
              switch(tolower(HorD))
              {
                case 'h': 
                {
                 int nh = n.Healing();
                 cout<<"Ninja's Health: "<<n.getHealth()<<endl;
                 break;
                }
                case 'd':
                {
                  srand(time(NULL));
                  if(rand() % 5 + 1 > 3)
                  {
                    int bsdmg = n.Damage();
                    int addmg = n.addDamage();
                    wiz.takeDamage(bsdmg + addmg);
                    cout<<"Ninja deals a damage of: "<<bsdmg + addmg<<" to Wizard! "<<endl
                        <<"Wizard's Health: "<<wiz.getHealth()<<endl;
                  }
                  else
                  {
                    int bsdmg = n.Damage();
                    wiz.takeDamage(bsdmg);
                    cout<<"Ninja deals a damage of: "<<bsdmg<<" to Wizard! "<<endl
                        <<"Wizard's Health: "<<wiz.getHealth()<<endl;
                  }
                  break;
                }
                default: 
                {
                  cout<<"Invalid Input! Please choose between heal or damage "<<endl;
                  break;
                }         
              }
            }
            HorD = 'a';
            cout<<WHITE;
            cout<<"********************************************************************************"<<endl<<endl;
          }
          if(wiz.getHealth() > n.getHealth())
          {
            cout<<"\t\t\t******************* WINNER IS WIZARD ******************** "<<endl;
          }
          else
          {
            cout<<"\t\t\t******************** WINNER IS NINJA ******************** "<<endl;
          }
          break;
        }
      }
      break;
    }
  }
}
