//____________________________________________________________________________
/*!

\class   genie::SPPHadronicSystemGenerator

\brief   Generates the 'final state' hadronic system in v SPP interactions.
         
         It adds the remnant nucleus (if any) and the baryon resonance decay 
         products at the GHEP record. The resonance decay products are pre-
         determined since in this thread we generate exclusive SPP reactions.
         The module uses a simple phase space decay.

         Is a concrete implementation of the EventRecordVisitorI interface.

\author  Costas Andreopoulos <C.V.Andreopoulos@rl.ac.uk>
         CCLRC, Rutherford Appleton Laboratory

\created November 23, 2004

*/
//____________________________________________________________________________

#ifndef _SPP_HADRONIC_SYSTEM_GENERATOR_H_
#define _SPP_HADRONIC_SYSTEM_GENERATOR_H_

#include <TGenPhaseSpace.h>

#include "EVGModules/HadronicSystemGenerator.h"

namespace genie {

class SPPHadronicSystemGenerator : public HadronicSystemGenerator {

public :
  SPPHadronicSystemGenerator();
  SPPHadronicSystemGenerator(string config);
  ~SPPHadronicSystemGenerator();

  //-- implement the EventRecordVisitorI interface
  void ProcessEventRecord(GHepRecord * event_rec) const;

private:
  void AddResonanceDecayProducts (GHepRecord * event_rec) const;

  mutable TGenPhaseSpace fPhaseSpaceGenerator;
};

}      // genie namespace

#endif // _SPP_HADRONIC_SYSTEM_GENERATOR_H_
