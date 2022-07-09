class Hero{
    public:
        int attack;
        int defence;
        char name;
        Hero(int attack, int defence, char name);
        bool operator==(const Hero* hero) const;
};

class Warrior : public Hero{
    public:
        Warrior(int attack, int defence, char name);
};

class Thief : public Hero{
    public:
        Thief(int attack, int defence, char name);
};
