#ifndef YOUREXTERNALBACKGROUNDSOURCE_HH
#define YOUREXTERNALBACKGROUNDSOURCE_HH

#include <G4LogicalVolume.hh>
#include <G4RotationMatrix.hh>
#include <G4Tubs.hh>
#include <G4Material.hh>
#include <G4PVPlacement.hh>
#include <G4VisAttributes.hh>
#include <G4SystemOfUnits.hh>

class YourExternalBackgroundSource {

    public:
        YourExternalBackgroundSource();
        ~YourExternalBackgroundSource();
    
    void Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial);
    G4LogicalVolume* GetLogicalVolume() const { return this->externalBackgroundLogicalVolume; }

    private:

        void InitialiseAttributes();

        G4double pRmin, pRmax, pDz;
        G4Tubs* externalBackgroundVolume;
        G4LogicalVolume* externalBackgroundLogicalVolume;
        G4VPhysicalVolume* externalBackgroundPhysicalVolume;
        G4RotationMatrix* rotationMatrix;
};

#endif