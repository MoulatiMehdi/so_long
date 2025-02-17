
typedef enum e_way
{
    WAY_LEFT = 1,
    WAY_UP = 2,
    WAY_RIGHT,
    WAY_DOWN,
} t_way;

typedef enum e_state
{
    STATE_IDLE = 1,
    STATE_WALK = 2,
    STATE_SWIM,
    STATE_GRAB,
} t_state;

typedef struct s_player
{
    int x;
    int y;
    t_way way;
    t_state state;

} t_player; 
