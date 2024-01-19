//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "lionTestApp.h"
#include "lionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
lionTestApp::validParams()
{
  InputParameters params = lionApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

lionTestApp::lionTestApp(InputParameters parameters) : MooseApp(parameters)
{
  lionTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

lionTestApp::~lionTestApp() {}

void
lionTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  lionApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"lionTestApp"});
    Registry::registerActionsTo(af, {"lionTestApp"});
  }
}

void
lionTestApp::registerApps()
{
  registerApp(lionApp);
  registerApp(lionTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
lionTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  lionTestApp::registerAll(f, af, s);
}
extern "C" void
lionTestApp__registerApps()
{
  lionTestApp::registerApps();
}
