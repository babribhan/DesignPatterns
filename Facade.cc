#include <iostream>
using namespace std;
class MisDepartment{
  public : 
    void submitNetworkRequet(){
      _state = 0;
    }
    bool checkOnStatus(){
      _state++;
      if ( _state == Complete ) 
        return true;
      return false;
    }
  private : 
    enum States
    {
      Received, DenyAllKnowledge, ReferClientToFacilities,
      FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
      ElectricianDidItWrong, DispatchTechnician, SignedOff, DoesNotWork,
      FixElectriciansWiring, Complete
    };
    int _state;
};
class ElectricianUnion{
  public : 
    void submitNetworkRequet(){
      _state = 0;
    }
    bool checkOnStatus(){
      _state++;
      if ( _state == Complete ) 
        return true;
      return false;
    }
  private : 
    enum States
    {
      Received, RejectTheForm, SizeTheJob, SmokeAndJokeBreak,
      WaitForAuthorization, DoTheWrongJob, BlameTheEngineer, WaitToPunchOut,
      DoHalfAJob, ComplainToEngineer, GetClarification, CompleteTheJob,
      TurnInThePaperwork, Complete
    };
    int _state;
};
class FacilitiesDepartment{
  public : 
    void submitNetworkRequet(){
      _state = 0;
    }
    bool checkOnStatus(){
      _state++;
      if ( _state == Complete ) 
        return true;
      return false;
    }
  private : 
    enum States
    {
      Received, AssignToEngineer, EngineerResearches, RequestIsNotPossible,
      EngineerLeavesCompany, AssignToNewEngineer, NewEngineerResearches,
      ReassignEngineer, EngineerReturns, EngineerResearchesAgain,
      EngineerFillsOutPaperWork, Complete
    };
    int _state;
};
class FacilitesFacade{
  public : 
    FacilitesFacade(){
      _count = 0;
    }
    void submitNetworkRequet(){
      _state = 0;
    }
    int getNumberOfCalls() const {
      return _count;
    }
    bool checkOnStatus(){
      _count++;
      /* Job Request has just been received */
      if ( _state == Received ){
        _state++;
        /* Forward the Request to Engineer */
        _engineer.submitNetworkRequet();
        cout << "submitted to Facilities - " << _count << " phone calls so far" << endl;
      } 
      else if ( _state == SubmitToEngineer ){
        /* If engineer is complete, forward to electrician */
        if ( _engineer.checkOnStatus()) {
          _state++;
          _electrician.submitNetworkRequet();
          cout << "submitted to Electrician - " << _count << " phone calls so far" << endl;
        }
      } 
      else if ( _state == SubmitToElectrician ){
        /* If electrician is complete, forward to technician. */
        if ( _electrician.checkOnStatus()) {
          _state++;
          _technician.submitNetworkRequet();
          cout << "submitted to Technician - " << _count << " phone calls so far" << endl;
        }
      } 
      else if ( _state == SubmitToTechnician ){
        /* If technician is done then job is done. */
        if ( _technician.checkOnStatus())
          return true;
      } 
      /* The Job is not entirely complete */
      return false;
    }
  private : 
    enum States
    {
      Received, SubmitToEngineer, SubmitToElectrician, SubmitToTechnician
    };
    int _state;
    int _count;
    FacilitiesDepartment _engineer;
    ElectricianUnion _electrician;
    MisDepartment _technician;
};
int main(){
  FacilitesFacade facilites;
  facilites.submitNetworkRequet();
  /* Keep checking until the job is done. */
  while (!facilites.checkOnStatus());
  cout << " the job is complete after  only " << facilites.getNumberOfCalls() << " phone calls "<<endl;
  return 0;
}
