#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;

public:
    class BombIterator {
    private:
        std::vector<DynamicObject*> refArr;
        int Index;
        DynamicObject* ptr;
    public:
        BombIterator(std::vector<DynamicObject*> ref) : refArr(ref), Index(-1), ptr(nullptr) { ++(*this); }
        void reset() { Index = -1;  ptr = nullptr; }

        BombIterator& operator++() {
            ++Index;
            for (; Index < refArr.size(); ++Index) {
                                              
                Bomb* pBomb = dynamic_cast<Bomb*>(refArr[Index]);
                if (pBomb != nullptr) {
                    ptr = refArr[Index];
                    break;
                }

            }
            if (Index == refArr.size()) {
                Index = -1;
                ptr = nullptr;
            }
            return *this;
        }
        BombIterator& operator++(int) {
            auto temp = *this;
            ++(*this);
            return temp;
        }

        BombIterator& operator--() {
            --Index;

            for (; Index >= 0; --Index) {
                Bomb* pBomb = dynamic_cast<Bomb*>(refArr[Index]);
                if (pBomb != nullptr) {
                    ptr = refArr[Index];
                    break;
                }
            }
            if (Index <= 0) {
                Index = -1;
                ptr = nullptr;
            }
            return *this;
        }
        BombIterator& operator--(int) {
            auto temp = *this;
            --(*this);
            return temp;
        }

        DynamicObject*& operator*() {
            return refArr.at(Index);
        }
        bool operator==(BombIterator it) {
            if (ptr == it.ptr && refArr == it.refArr) {
                return true;
            }
            return false;
        }
        bool operator!=(BombIterator it) {
            return !(it == *this);
        }

    };
    BombIterator begin() const {
        BombIterator it(vecDynamicObj);
        return it;
    }
    BombIterator end() const {
        BombIterator it(vecDynamicObj);
        it.reset();
        return it;
    }
};
