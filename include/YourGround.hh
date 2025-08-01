#ifndef YOURGORUND_HH
#define YOURGORUND_HH

#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4Types.hh>
#include <G4PVPlacement.hh>
#include <G4VisAttributes.hh>
#include <G4Material.hh>
#include <G4SystemOfUnits.hh>

class YourGround{

    public:
    
        YourGround();
        ~YourGround();
        void Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial);

    private:

    void InitialiseAttributes();

    G4double lengthX, lengthY, lengthZ;
    G4Box* groundVolume;
    G4LogicalVolume* groundLogicalVolume;
    G4VPhysicalVolume* groundPhysicalVolume;



};


#endif