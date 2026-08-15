#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <time.h>
#include <math.h>

// Agent
const int True = 1;
const int False = 0;

int agent = True;

// Hardware and software information


#ifdef _WIN32
    const int OS = 0;
    #include <GL/gl.h>  // Windows
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_OS_IPHONE
        const int OS = 1;

        
    #else
        const int OS = 2;

        #include <OpenGL/gl.h>  // macOS
    #endif
#elif __linux__
    const int OS = 3;
    #include <GL/gl.h>  // Linux
#elif __unix__
    const int OS = 4;
#elif defined(_POSIX_VERSION)
    const int OS = 5;

#else
    const int OS = 6;

#endif

int arc_os_id(){
    return OS;
}

char* arc_os_name(){
    if (OS == 0){
        return "windows";
    } else if (OS == 1){
        return "ios";
    } else if (OS == 2){
        return "macos";
    } else if (OS == 3){
        return "linux";
    } else if (OS == 4){
        return "unix";
    } else if (OS == 5){
        return "posix";
    } else if (OS == 6){
        return "Unknown";
    }

    return "Unknown";
}


int arc_monitor_count(){
    return GetMonitorCount();
}

int arc_current_monitor(){
    return GetCurrentMonitor();
}

int arc_current_monitor_refresh_rate(){
    return GetMonitorRefreshRate(arc_current_monitor());
}

int arc_monitor_refresh_rate(int monitor_index){
    if (agent){
        if ((monitor_index+1) > arc_monitor_count()){
            printf("Agent warning, detected a monitor out of range, defaulting to current monitor");
            fflush(stdout);
            return arc_current_monitor_refresh_rate();
        }
    }
    return GetMonitorRefreshRate(monitor_index);
}

int arc_current_monitor_width(){
    return GetMonitorWidth(arc_current_monitor());
}

int arc_monitor_width(int monitor_index){
    if (agent){
        if ((monitor_index+1) > arc_monitor_count()){
            printf("Agent warning, detected a monitor out of range, defaulting to current monitor");
            fflush(stdout);
            return arc_current_monitor_width();
        }
    }
    return GetMonitorWidth(monitor_index);
}

int arc_current_monitor_height(){
    return GetMonitorHeight(arc_current_monitor());
}

int arc_monitor_height(int monitor_index){
    if (agent){
        if ((monitor_index+1) > arc_monitor_count()){
            printf("Agent warning, detected a monitor out of range, defaulting to current monitor");
            fflush(stdout);
            return arc_current_monitor_height();
        }
    }
    return GetMonitorHeight(monitor_index);
}

int arc_current_monitor_physical_width(){
    return GetMonitorPhysicalWidth(arc_current_monitor());
}

int arc_monitor_physical_width(int monitor_index){
    if (agent){
        if ((monitor_index+1) > arc_monitor_count()){
            printf("Agent warning, detected a monitor out of range, defaulting to current monitor");
            fflush(stdout);
            return arc_current_monitor_physical_width();
        }
    }
    return GetMonitorPhysicalWidth(monitor_index);
}

int arc_current_monitor_physical_height(){
    return GetMonitorPhysicalHeight(arc_current_monitor());
}

int arc_monitor_physical_height(int monitor_index){
    if (agent){
        if ((monitor_index+1) > arc_monitor_count()){
            printf("Agent warning, detected a monitor out of range, defaulting to current monitor");
            fflush(stdout);
            return arc_current_monitor_physical_height();
        }
    }
    return GetMonitorPhysicalHeight(monitor_index);
}


char* arc_get_gpu_type(){
    char* vendor = (char*)glGetString(GL_VENDOR);
    return vendor;
}

char* arc_get_gpu_version(){
    char* version = (char*)glGetString(GL_RENDERER);
    return version;
}

// Math API

unsigned int arc_abs(int number){
    return abs(number);
}

double arc_absd(double number){
    return fabs(number);
}

double arc_absoluted(double number){
    return arc_absd(number);
}

int arc_absolute(int number){
    return arc_abs(number);
}

int arc_min(int a, int b){
    int number = a;

    if (number > b){
        number = b;
    } else {
        number = number;
    }

    return number;
}

int arc_minimum(int a, int b){
    return arc_min(a, b);
}

int arc_max(int a, int b){
    int number = a;
    if (number > b){
        number = number;
    } else {
        number = b;
    }

    return number;
}

int arc_maximum(int a, int b){
    return arc_max(a, b);
}

double arc_mind(double a, double b){
    double number = a;

    if (number > b){
        number = b;
    } else {
        number = number;
    }

    return number;
}

double arc_minimumd(double a, double b){
    return arc_mind(a, b);
}

double arc_maxd(double a, double b){
    double number = a;
    if (number > b){
        number = number;
    } else {
        number = b;
    }

    return number;
}

double arc_maximumd(double a, double b){
    return arc_maxd(a, b);
}

int arc_clamp(int value, int min, int max){
    int number = value;
    if (number > min && number < max){
        number = value;
    } else {
        if (number < min){
            number = min;
        } else if (number > max){
            number = max;
        }
    }

    return number;
}

double arc_clampd(double value, double min, double max){
    double number = value;
    if (number > min && number < max){
        number = value;
    } else {
        if (number < min){
            number = min;
        } else if (number > max){
            number = max;
        }
    }

    return number;
}

double arc_grange(int index, int start, double step){
    double num = start;
    num = num + (step * index); 

    return num;
}

int arc_sum(int* array, int length){
    int summed = 0;
    for (int i=0; i<length; i++){
        summed = summed + array[i];
    }

    return summed;
}

long int arc_sum_long(long int* array, int length){
    long int summed = 0;
    for (int i=0; i<length; i++){
        summed = summed + array[i];
    }

    return summed;
}

double arc_sumd(double* array, int length){
    double summed = 0;
    for (int i=0; i<length; i++){
        summed = summed + array[i];
    }

    return summed;
}

double arc_mean(int* array, int length){
    double final = arc_sum(array, length);
    final = final / length;
    return final;
}

double arc_meand(double* array, int length){
    double final = arc_sumd(array, length);
    final = final / length;
    return final;
}

double arc_average(int* array, int length){
    return arc_mean(array, length);
}

double arc_averaged(double* array, int length){
    return arc_meand(array, length);
}

double arc_delta(int fps){
    if (agent){
        if (fps == 0){
            return 0;
        }
    }
    return arc_absd(1.0 / fps);
}

int arc_fps(double delta){
    if (agent){
        if (delta == 0){
            return 0;
        }
    }
    return arc_abs(1.0 / delta);
}

// ARC input

enum keys{
    arrow_up = KEY_UP,
    arrow_down = KEY_DOWN,
    arrow_left = KEY_LEFT,
    arrow_right = KEY_RIGHT,
    w = KEY_W,
    a = KEY_A,
    s = KEY_S,
    d = KEY_D,
    q = KEY_Q,
    e = KEY_E,
    z = KEY_Z,
    x = KEY_X,
    c = KEY_C,
    r = KEY_R,
    f = KEY_F,
    v = KEY_V,
    b = KEY_B,
    g = KEY_G,
    t = KEY_T,
    y = KEY_Y,
    h = KEY_H,
    n = KEY_N,
    u = KEY_U,
    j = KEY_J,
    m = KEY_M,
    k = KEY_K,
    i = KEY_I,
    o = KEY_O,
    l = KEY_L,
    p = KEY_P,
    one = KEY_ONE,
    two = KEY_TWO,
    three = KEY_THREE,
    four = KEY_FOUR,
    five = KEY_FIVE,
    six = KEY_SIX,
    seven = KEY_SEVEN,
    eight = KEY_EIGHT,
    nine = KEY_NINE,
    zero = KEY_ZERO,
    enter = KEY_ENTER,
    lshift = KEY_LEFT_SHIFT,
    rshift = KEY_RIGHT_SHIFT,
    lctrl = KEY_LEFT_CONTROL,
    rctrl = KEY_RIGHT_CONTROL,
    tab = KEY_TAB,
    space = KEY_SPACE,
    esc = KEY_ESCAPE,
    jump = KEY_SPACE,
    lalt = KEY_LEFT_ALT,
    ralt = KEY_RIGHT_ALT,
    f1 = KEY_F1,
    f2 = KEY_F2,
    f3 = KEY_F3,
    f4 = KEY_F4,
    f5 = KEY_F5,
    f6 = KEY_F6,
    f7 = KEY_F7,
    f8 = KEY_F8,
    f9 = KEY_F9,
    f10 = KEY_F10,
    f11 = KEY_F11,
    f12 = KEY_F12,
};


int arc_is_key_down(enum keys key){
    return IsKeyDown(key);
}

int arc_is_key_up(enum keys key){
    return IsKeyUp(key);
}

int arc_is_key_pressed(enum keys key){
    return IsKeyPressed(key);
}

int arc_is_key_released(enum keys key){
    return IsKeyReleased(key);
}

int arc_is_right_mouse_btn_down(){
    return IsMouseButtonDown(MOUSE_RIGHT_BUTTON);
}

int arc_is_right_mouse_btn_up(){
    return IsMouseButtonUp(MOUSE_RIGHT_BUTTON);
}

int arc_is_left_mouse_btn_down(){
    return IsMouseButtonDown(MOUSE_LEFT_BUTTON);
}

int arc_is_left_mouse_btn_up(){
    return IsMouseButtonUp(MOUSE_LEFT_BUTTON);
}

int arc_is_left_mouse_btn_pressed(){
    return IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}


int arc_is_right_mouse_btn_pressed(){
    return IsMouseButtonPressed(MOUSE_RIGHT_BUTTON);
}


int arc_is_left_mouse_btn_released(){
    return IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
}

int arc_is_right_mouse_btn_released(){
    return IsMouseButtonReleased(MOUSE_RIGHT_BUTTON);
}


// ARC I/O

typedef struct {
    FILE *fptr;
} arc_file;

arc_file open_file(const char* filename, const char* mode){
    arc_file file;

    if (agent){
        if (fopen(filename, "r")){
            file.fptr = fopen(filename, mode);
        } else {
            FILE *fp = fopen(filename, "w"); // to create the file 
            file.fptr = fopen(filename, mode);
        }
    } else {
        file.fptr = fopen(filename, mode);
    }

    return file;
}

char* read_file(arc_file file){
    
}

void close_file(arc_file file){
    fclose(file.fptr);
}

// ARC debugging

void arc_msg(const char* text){
    printf("%s", text);
    fflush(stdout);
}

// ARC core

typedef enum {
    LOW_END = 30, // 30FPS
    MID_RANGE = 60, // 60FPS
    HIGH_END = 144, // 144FPS
    MAX = 0,
} arc_device_fps;


void arc_turn_agent_off(){
    agent = False;
    printf("⚠️ Agent disabled. the agent is desgined to help you finish development fast and ship games without worrying about bugs, for most games, consider turning it on.\n");
}

void arc_turn_agent_on(){
    agent = True;
}

int arc_is_full_screen(){
    return IsWindowFullscreen();
}

void arc_toggle_full_screen(){
    ToggleFullscreen();
}

void arc_full_screen(){
    if (!arc_is_full_screen()){
        arc_toggle_full_screen();
    }
}

void arc_create_game_window(int width, int height, char* title){
    if (agent){
        if (width > arc_current_monitor_width()){
            width = 350;
            printf("⚠️ Agent Warning. found a window with a width more than %d, defaulting to 350\n", arc_current_monitor_width());

        } else if (width < 100){
            width = 350;
            printf("⚠️ Agent Warning. found a window with a width less than 100, defaulting to 350\n");

        }
        if (height > arc_current_monitor_height()){
            height = 350;
            printf("⚠️ Agent Warning. found a window with a height more than %d, defaulting to 350\n", arc_current_monitor_height());

        } else if (height < 100){
            height = 350;
            printf("⚠️ Agent Warning. found a window with a height less than 100, defaulting to 350\n");

        }
    }

    InitWindow(width, height, title);
}

void arc_set_fps(int fps){
    if (agent){
        if (fps > arc_current_monitor_refresh_rate()){
            fps = arc_current_monitor_refresh_rate();
            printf("⚠️ Agent Warning. super high fps numbers detected, defaulting to %dfps\n", arc_current_monitor_refresh_rate());

        } else if (fps < 0){
            fps = arc_current_monitor_refresh_rate();
            printf("⚠️ Agent Warning. negative fps numbers detected, defaulting to %dfps\n", arc_current_monitor_refresh_rate());

        }
    }
    SetTargetFPS(fps);
}

void arc_close_window(){
    CloseWindow();
}

int arc_game_running(){
    return !WindowShouldClose();
}

// ARC Positions

typedef struct{
    double x;
    double y;
} arc_position;

arc_position arc_create_position(double x, double y){
    arc_position position = {x, y};

    return position;
}

arc_position arc_change_position_to(arc_position *pos, double x, double y){
    pos->x = x;
    pos->y = y;
    return *pos;
}

Vector2 arc_convert_pos_to_raylib_vector(arc_position *pos){

    Vector2 vec = {(float)pos->x, (float)pos->y};
    return vec;
}

arc_position arc_raylib_vector2_to_position(Vector2 *vector){
    arc_position pos = {(double)vector->x, (double)vector->y};
    return pos;
}

// ARC sizing
typedef struct {
    int width;
    int height;
} arc_size;

arc_size arc_create_size(int width, int height){
    arc_size size = {width, height};

    return size;
}

// ARC Window managing

int arc_get_window_width(){
    return GetScreenWidth();
}

int arc_get_window_height(){
    return GetScreenHeight();
}

arc_size arc_get_window_size(){
    int width = arc_get_window_width();
    int height = arc_get_window_height();

    return arc_create_size(width, height);
}

arc_position arc_get_window_center(){
    int width = arc_get_window_width();
    int height = arc_get_window_height();

    return arc_create_position(width/2, height/2);
}

// ARC Sprites

typedef struct {
    Texture2D sprite;
    arc_size size;
} arc_sprite;

arc_sprite arc_create_sprite(const char* path){
    arc_sprite sp;

    if (agent){
        if (fopen(path, "r")){
            sp.sprite = LoadTexture(path);
        } else {
            // check for ARC's own logo
            if (fopen("arc-logo.png", "r")){
                sp.sprite = LoadTexture("arc-logo.png");
            } else {
                return sp; // actually safe, because ARC checks if SP is empty
            }
        }
    } else {
        sp.sprite = LoadTexture(path);
    }

    sp.size = arc_create_size(sp.sprite.width, sp.sprite.height);

    return sp;
}

int arc_confirm_sprite_health(arc_sprite *sp){
    if (sp == NULL){
        return False;
    }

    if (!IsTextureValid(sp->sprite)){
        return False;
    }

    if (sp->sprite.width != sp->size.width || sp->size.height != sp->size.height){
        return False;
    }

    return True;
}

// ARC objects
typedef struct {
    arc_sprite sprite;
    arc_position position;
} arc_object;

// ARC strings

typedef struct {
    char* content;
    int length;
    int size_in_bytes;
} arc_string;

int arc_string_length(arc_string *string){
    int length = 0;
    while (string->content[length] != '\0'){
        length++;
    }

    string->length = length;
    string->size_in_bytes = length+1;

    return length;
}

int arc_string_length_instant(arc_string string){
    return string.length;
}

void arc_append_to_string(arc_string* string, const char* to_append){
    int length = 0;

    while (to_append[length] != '\0'){
        length++;
    }

    string->content = realloc(string->content, string->size_in_bytes + length);
    int i = string->length; // \0 is on that 
    int index = 0;
    
    while (to_append[index] != '\0'){
        string->content[i] = to_append[index];
        index++;
        i++;
    }

    string->content[i] = '\0';
    string->length = i;
    string->size_in_bytes = i+1;
}

void arc_append_to_string_repeat(arc_string* string, const char* to_append, int how_many){
    int i = 0;

    while (i < how_many){
        arc_append_to_string(string, to_append);
        i++;
    }
}

arc_string arc_create_string(const char* value){
    // calculating length
    int length = 0;
    while (value[length] != '\0'){
        length++;
    }

    arc_string string;

    string.length = length;
    string.size_in_bytes = length+1; // hello + \0
    string.content = malloc(string.size_in_bytes * sizeof(char));

    // copying the string

    int index = 0;

    while (index < string.length){
        string.content[index] = value[index];
        index++;
    }

    string.content[index] = '\0';

    return string;
}

char arc_get_index(arc_string string, int index){
    if (agent){
        if (arc_string_length_instant(string) == 0){
            return '\0'; // Because there is nothing else   
        } else if (arc_string_length_instant(string) <= index){
            return '\0';
        }
    }

    return string.content[index];
}

int arc_string_to_integer(arc_string string){
    int index = 0;
    int integer = 0;
    int written = 0;
    int is_number_negative = 0;

    while(string.content[index] != '\0'){
        switch (string.content[index]){
            case '-':
                if (written == 0){
                    is_number_negative = 1;
                }
                break;
            case '0':
                integer = (integer * 10) + 0;
                written = 1;
                break;
            case '1':
                (is_number_negative == 0) ? (integer = (integer * 10) + 1) : (integer = (integer * 10) - 1);
                written = 1;
                break;
            case '2':
                (is_number_negative == 0) ? (integer = (integer * 10) + 2) : (integer = (integer * 10) - 2);
                written = 1;
                break;
            case '3':
                (is_number_negative == 0) ? (integer = (integer * 10) + 3) : (integer = (integer * 10) - 3);
                written = 1;
                break;
            case '4':
                (is_number_negative == 0) ? (integer = (integer * 10) + 4) : (integer = (integer * 10) - 4);
                written = 1;
                break;
            case '5':
                (is_number_negative == 0) ? (integer = (integer * 10) + 5) : (integer = (integer * 10) - 5);
                written = 1;
                break;
            case '6':
                (is_number_negative == 0) ? (integer = (integer * 10) + 6) : (integer = (integer * 10) - 6);
                written = 1;
                break;
            case '7':
                (is_number_negative == 0) ? (integer = (integer * 10) + 7) : (integer = (integer * 10) - 7);
                written = 1;
                break;
            case '8':
                (is_number_negative == 0) ? (integer = (integer * 10) + 8) : (integer = (integer * 10) - 8);
                written = 1;
                break;
            case '9':
                (is_number_negative == 0) ? (integer = (integer * 10) + 9) : (integer = (integer * 10) - 9);
                written = 1;
                break;
            default:
                break;

        }

        index++;
    }

    return integer;
}

void arc_print_string(arc_string str){
    printf("%s", str.content);
}

void arc_println_string(arc_string str){
    printf("%s\n", str.content);
}

void arc_free_string(arc_string *string){
    free(string->content);
    string->length = 0;
    string->size_in_bytes = 0;
}

arc_string arc_integer_to_string(int integer){
    int secondary_int = 0;
    int num = 0;

    arc_string str = arc_create_string("");

    int target = 10;
    
    if (integer < 0){
        arc_append_to_string(&str, "-");
    }

    while ((int)(num/10) != integer){
        secondary_int = integer;

        while (secondary_int >= target || secondary_int <= -target){
            secondary_int /= 10;
            
        }

        secondary_int = secondary_int - num;

        num += secondary_int;
        num *= 10;

        // 123 --> 12 --> 1 - 0 = 1;
        // 123 --> 12 --> 12 - 10 = 2;
        // 123 --> 123 --> 123 - 120 = 3;

        switch (secondary_int){
            case 0:
                arc_append_to_string(&str, "0");
                break;
            case 1:
                arc_append_to_string(&str, "1");
                break;
            case 2:
                arc_append_to_string(&str, "2"); 
                break;
            case 3:
                arc_append_to_string(&str, "3");
                break;
            case 4:
                arc_append_to_string(&str, "4");
                break;
            case 5:
                arc_append_to_string(&str, "5");
                break;
            case 6:
                arc_append_to_string(&str, "6");
                break;
            case 7:
                arc_append_to_string(&str, "7");
                break;
            case 8:
                arc_append_to_string(&str, "8");
                break;
            case 9:
                arc_append_to_string(&str, "9");
                break;
            case -1:
                arc_append_to_string(&str, "1");
                break;
            case -2:
                arc_append_to_string(&str, "2"); 
                break;
            case -3:
                arc_append_to_string(&str, "3");
                break;
            case -4:
                arc_append_to_string(&str, "4");
                break;
            case -5:
                arc_append_to_string(&str, "5");
                break;
            case -6:
                arc_append_to_string(&str, "6");
                break;
            case -7:
                arc_append_to_string(&str, "7");
                break;
            case -8:
                arc_append_to_string(&str, "8");
                break;
            case -9:
                arc_append_to_string(&str, "9");
                break;


            default:
                break;
        }

        target *= 10;
    }

    return str;
}

// Arc Random

int random_system = False;

void arc_init_random(){
    srand(time(NULL));
    random_system = True;
}

int arc_random_integer(int min, int max){
    if (agent){
        if (!random_system){
            arc_init_random();
        }
    }

    max = max + 1; // if max is 100 make it 101, so the range is in 100

    int random_number = (rand() % (max - min)) + min;

    return random_number;
}

double arc_random_double(int min, int max){
    if (agent){
        if (!random_system){
            arc_init_random();
        }
    }

    double decimal_number = arc_random_integer(0, 999);

    int number = arc_random_integer(min, max);

    double rand_double = min + 0.0;

    if (decimal_number >= 100){
        rand_double = (double)(number + (decimal_number / 1000));
    } else if (decimal_number >= 10){
        rand_double = (double)(number + (decimal_number / 100));
    } else {
        rand_double = (double)(number + (decimal_number / 10));
    }


    return rand_double;
}

arc_position arc_random_position(int minx, int maxx, int miny, int maxy){
    if (agent){
        if (!random_system){
            arc_init_random();
        }
    }

    arc_position pos;

    double x = arc_random_double(minx, maxx);
    double y = arc_random_double(miny, maxy);

    pos.x = x;
    pos.y = y;
    
    return pos;
}

int arc_sample(int* array, int length){
    if (agent){
        if (!random_system){
            arc_init_random();
        }
    }
    int max_index = length - 1;
    int random_index = arc_random_integer(0, max_index);

    return array[random_index];
}

void arc_update_seed_to_now(){
    if (agent){
        if (!random_system){
            arc_init_random();
            return;
        }
    }
    srand(time(NULL));
}

void arc_update_seed_to_random(){
    if (agent){
        if (!random_system){
            arc_init_random();
            return;
        }
    }

    srand(arc_random_integer(1, 1000));
}

// Arc time

clock_t arc_now(){
    return clock();
}

// Arc counters

typedef struct {
    long double count;
    unsigned int edits;
} arc_counter;  

void arc_randomize_counter_integer(arc_counter *counter, int min, int max){
    counter->count = (double)arc_random_integer(min, max);
    counter->edits++;
}

void arc_randomize_counter_double(arc_counter *counter, int min, int max){
    counter->count = arc_random_double(min, max);
    counter->edits++;

}

void arc_counter_add(arc_counter *counter, double number){
    counter->count += number;
    counter->edits++;

}

void arc_counter_subtract(arc_counter *counter, double number){
    counter->count -= number;
    counter->edits++;

}

int arc_get_counter_integer(arc_counter *counter){
    return (int)counter->count;
}

double arc_get_counter(arc_counter *counter){
    return counter->count;
}

void arc_double_counter(arc_counter *counter){
    counter->count *= 2;
    counter->edits++;
}

void arc_multiply_counter(arc_counter *counter, double number){
    counter->count *= number;
    counter->edits++;
}

void arc_abs_counter(arc_counter *counter){
    counter->count = arc_absd(counter->count);
    counter->edits++;
}

void arc_divide_counter(arc_counter *counter, double number){
    if (agent){
        if (number == 0.0){
            return;
        }
    }

    counter->count /= number;
    counter->edits++;

}

void arc_counter_reset(arc_counter *counter){
    counter->count = 0;
    counter->edits++;
}

void arc_counter_full_reset(arc_counter *counter){
    counter->count = 0;
    counter->edits = 0;
}

void arc_pow_counter(arc_counter *counter, double number){
    counter->count = powl(counter->count, number);
    counter->edits++;
}

arc_counter arc_create_counter(double count){
    arc_counter counter;

    counter.count = count;
    counter.edits = 0;

    return counter;
}

int main(){
    arc_turn_agent_on();
    arc_create_game_window(8100, 8100, "first game ever");
    arc_set_fps(-22);
    arc_turn_agent_off();
    
    while (arc_game_running()){
        BeginDrawing();
        if (arc_is_key_down(arrow_up)){
            arc_msg("Bam");
        }
        EndDrawing();
    }

    arc_game_running();
    return 0;
}