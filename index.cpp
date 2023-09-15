#include <stdio.h>
#include <stdlib.h>

void str_copy(char *src, char *dest) {
    int i = 0;
    while (src[i] != 0) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
}

struct Soldier {
    char name[20];
    int health;
    int power;
    int speed;
};

void create_soldier(Soldier &target, char *name, int h, int p, int s) {
    str_copy(name, target.name);
    target.health = h;
    target.power = p;
    target.speed = s;
}

bool didDie(Soldier s) {
    return s.health < 0; 
}

void attack(Soldier attacker, Soldier &victim) {
    victim.health -= attacker.power;
}

void tell_left_health(Soldier s) {
    printf("health left - %s : %d \n", s.name, s.health);
}

void print_soldier_info(Soldier aSoldier) {
    printf("health: %d \n",aSoldier.health);
    printf("power: %d \n", aSoldier.power);
    printf("speed: %d \n", aSoldier.speed);
}

int alive_count(Soldier *soldiers, int size) {
    int count = 0;

    int i = 0;
    while(i < size) {
        
        if (!didDie(soldiers[i])) {
            count++;
        }
        i++;
    }
    return count;
}

Soldier find_alive(Soldier *soldiers, int size) {
    int i = 0;
    while(i < size) {
        
        if (!didDie(soldiers[i])) {
            return soldiers[i];
        }
        i++;
    }
}

int main() {
    Soldier soldiers[10];

    create_soldier(soldiers[0], "Soldier1", 23, 1, 5);
    create_soldier(soldiers[1], "Soldier2", 43, 12, 5);
    create_soldier(soldiers[2], "Soldier3", 57, 19, 5);
    create_soldier(soldiers[3], "Soldier4", 65, 4, 5);
    create_soldier(soldiers[4], "Soldier5", 110, 1, 5);
    create_soldier(soldiers[5], "Soldier6", 32, 16, 5);
    create_soldier(soldiers[6], "Soldier7", 71, 11, 5);
    create_soldier(soldiers[7], "Ssoldier8", 23, 41, 5);
    create_soldier(soldiers[8], "Soldier9", 64, 8, 5);
    create_soldier(soldiers[9], "Soldier10", 63, 19, 5);

    int i = 0;
    while (true) {
        int attackerIndex = i % 10;
        Soldier *attacker = &soldiers[i];

        int j = 0;
        while (j < 10) {
            Soldier *victim = &soldiers[j];
            
            if (attacker != victim) {
                if (!didDie(*victim)) {
                    attack(*attacker, *victim);
                    tell_left_health(*victim);
                }
            }
            j++;
        }

        if (alive_count(soldiers, 10) == 1 ) {
            break;
        }
        i++;
    }

    Soldier winner = find_alive(soldiers, 10);
    printf("winner is %s \n", winner.name);
}