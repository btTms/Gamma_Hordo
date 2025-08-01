#ifndef YOURWORLDBOX_HH
#define YOURWORLDBOX_HH

#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4Material.hh>
#include <G4NistManager.hh>
#include <G4SystemOfUnits.hh>
#include <G4PVPlacement.hh>
#include <G4VPhysicalVolume.hh>

class YourWorldBox{

    public:

        YourWorldBox();
        ~YourWorldBox();

        G4VPhysicalVolume* GetWorldPhysicalVolume() const { return this->worldPhysicalVolume; }
        G4LogicalVolume* GetLogicalVolume() const { return this->worldLogicalVolume; }

    private:
    G4NistManager* nistManager;

    G4Material* worldMaterial;
    G4double worldSize;
    G4Box* worldVolume;
    G4LogicalVolume* worldLogicalVolume;
    G4VPhysicalVolume* worldPhysicalVolume;

};


#endif