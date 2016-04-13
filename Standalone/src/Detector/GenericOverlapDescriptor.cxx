///////////////////////////////////////////////////////////////////
// GenericOverlapDescriptor.cxx, ACTS project
///////////////////////////////////////////////////////////////////

// Geometry module
#include "Detector/GenericOverlapDescriptor.h"
#include "Detector/DetectorElementBase.h"
#include "Surfaces/Surface.h"

bool Acts::GenericOverlapDescriptor::reachableSurfaces(std::vector<const Surface*>& cSurfaces, 
                                                      const Surface& sf,
                                                      const Vector3D&,
                                                      const Vector3D&,
                                                      int searchMode) const 
{
                                                          
    // first add the target surface - it's always worth a try
    cSurfaces.push_back(&sf);                                                         

    // now get the neighbours of the detector element
    if (sf.associatedDetectorElement()){
        // not loop over them and stuff them into the return vector without asking
        for (auto& debm : sf.associatedDetectorElement()->binmembers()){
                cSurfaces.push_back(&(debm->surface()));   
        }
        // not loop over them and stuff them into the return vector without asking
        for (auto& den : sf.associatedDetectorElement()->neighbours()){
            // get the neighbours 
            cSurfaces.push_back(&(den->surface()));  
            // and teh bin members of the neighbours
            for (auto& denbm : den->binmembers())
                if (denbm)
                    cSurfaces.push_back(&(denbm->surface()));  
        }                                                       
    }
    return false;
}
     
