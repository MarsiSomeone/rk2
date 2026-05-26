#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>

class Monster {
public:
    virtual ~Monster() = default;
    virtual std::string Name() const = 0;
    virtual int AttackAbility() const = 0;
    virtual int DefenseAbility() const = 0;
};

class Slime : public Monster {
public:
    std::string Name() const override { return "Slime"; }
    int AttackAbility() const override { return 6; }
    int DefenseAbility() const override { return 20; }
};

class Goblin : public Monster {
public:
    std::string Name() const override { return "Goblin"; }
    int AttackAbility() const override { return 30; }
    int DefenseAbility() const override { return 10; }
};

class Dragon : public Monster {
public:
    std::string Name() const override { return "Dragon"; }
    int AttackAbility() const override { return 1000; }
    int DefenseAbility() const override { return 500; }
};

class Pet {
public:
    virtual ~Pet() = default;
    virtual std::string Name() const = 0;
    virtual int CutenessAbility() const = 0;
    virtual int BattleBonus() const = 0;
};

class Puppy : public Pet {
public:
    std::string Name() const override { return "Puppy"; }
    int CutenessAbility() const override { return 50; }
    int BattleBonus() const override { return 5; }
};

class Cat : public Pet {
public:
    std::string Name() const override { return "Cat"; }
    int CutenessAbility() const override { return 40; }
    int BattleBonus() const override { return 10; }
};

// Статический адаптер (compile-time)
template <typename MonsterType, 
          typename = std::enable_if_t<std::is_base_of<Monster, MonsterType>::value>>
class PetAdapterStatic : public Pet {
public:
    std::string Name() const override { return monster_.Name(); }
    int CutenessAbility() const override { 
        return monster_.DefenseAbility() - 2 * monster_.AttackAbility(); 
    }
    int BattleBonus() const override { 
        return monster_.AttackAbility() + monster_.DefenseAbility() / 2; 
    }
private:
    MonsterType monster_;
};

// Динамический адаптер (run-time)
class PetAdapterDynamic : public Pet {
public:
    explicit PetAdapterDynamic(std::unique_ptr<Monster>&& monster)
        : monster_(std::move(monster)) {}

    std::unique_ptr<Monster> ChangeMonster(std::unique_ptr<Monster>&& monster) {
        std::unique_ptr<Monster> returnedMonster = std::move(monster_);
        monster_ = std::move(monster); 
        return returnedMonster;
    }

    std::string Name() const override { return monster_->Name(); }
    int CutenessAbility() const override { 
        return monster_->DefenseAbility() - 2 * monster_->AttackAbility(); 
    }
    int BattleBonus() const override { 
        return monster_->AttackAbility() + monster_->DefenseAbility() / 2; 
    }
private:
    std::unique_ptr<Monster> monster_;
};
