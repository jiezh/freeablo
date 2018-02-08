
#pragma once

#include "actor.h"

#include <boost/signals2/signal.hpp>

namespace FAWorld
{
    class PlayerBehaviour;

    class Player : public Actor
    {
    public:
        static const std::string typeId;
        const std::string& getTypeId() override { return typeId; }

        Player(World& world);
        Player(World& world, const std::string& className, const DiabloExe::CharacterStats& charStats);
        void initCommon();
        Player(World& world, FASaveGame::GameLoader& loader, const DiabloExe::DiabloExe& exe);
        void save(FASaveGame::GameSaver& saver);

        virtual ~Player();
        void setSpriteClass(std::string className);
        void updateSprites() override;
        bool dropItem(const FAWorld::Tile& clickedTile);

        virtual void update(bool noclip) override;

        PlayerBehaviour* getPlayerBehaviour() { return (PlayerBehaviour*)mBehaviour.get(); }
        int getTotalGold() const;

        boost::signals2::signal<void(const std::pair<int32_t, int32_t>&)> positionReached;

    private:
        void init(const std::string& className, const DiabloExe::CharacterStats& charStats);
        bool canTalkTo(Actor* actor);

        std::string mClassName;
    };
}
