#ifndef YOURCOLLIMATORLAYER_HH
#define YOURCOLLIMATORLAYER_HH

#include <G4LogicalVolume.hh>
#include <G4RotationMatrix.hh>
#include <G4Trap.hh>
#include <G4Tubs.hh>
#include <G4Material.hh>
#include <G4PVPlacement.hh>
#include <G4Types.hh>
#include <G4VisAttributes.hh>
#include <G4SystemOfUnits.hh>
#include <G4SubtractionSolid.hh>

class YourCollimatorLayer{

    public:
        YourCollimatorLayer(G4double rotationAngle, G4double pRmin, G4double pRmax, G4double pDz);
        ~YourCollimatorLayer();

        void Build(G4LogicalVolume* motherVolume, G4Material* material, G4ThreeVector translation);

        void BuildTrapezoid();

    private:

        void InitialiseAttributes();

        G4Trap* trapezoid;
        G4double pDx1, pDx2, pDy1, pDy2, pDzTrap;
        G4RotationMatrix* trapezoidRotationMatrix;
        G4ThreeVector trapezoidTranslation;

        G4SubtractionSolid* actualCollimatorLayerVolume;
        G4double pRmin, pRmax, pDz;
        G4Tubs* collimatorLayerVolume;
        G4LogicalVolume* collimatorLayerLogicalVolume;
        G4VPhysicalVolume* collimatorLayerPhysicalVolume;
        G4RotationMatrix* rotationMatrix;

};

#endif