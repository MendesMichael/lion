#include "lionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
lionApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

lionApp::lionApp(InputParameters parameters) : MooseApp(parameters)
{
  lionApp::registerAll(_factory, _action_factory, _syntax);
}

lionApp::~lionApp() {}

void 
lionApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<lionApp>(f, af, s);
  Registry::registerObjectsTo(f, {"lionApp"});
  Registry::registerActionsTo(af, {"lionApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
lionApp::registerApps()
{
  registerApp(lionApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
lionApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  lionApp::registerAll(f, af, s);
}
extern "C" void
lionApp__registerApps()
{
  lionApp::registerApps();
}
