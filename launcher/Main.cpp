// SPDX-FileCopyrightText: 2022 Admer Šuko
// SPDX-License-Identifier: MIT

#include "Precompiled.hpp"
#include <iostream>

int main( int argc, char** argv )
{
	adm::Library engineLibrary = adm::Library( "BtxEngine" );
	if ( !engineLibrary )
	{
		std::cout << "Can't load BtxEngine library" << std::endl;
		return 1;
	}

	EngineImportFn* engineImportFunction = engineLibrary.FindFunction<EngineImportFn>( EngineImportFunctionName );
	if ( nullptr == engineImportFunction )
	{
		std::cout << "Can't load function '" << EngineImportFunctionName << "'" << std::endl;
		return 2;
	}

	IEngine* engine = engineImportFunction();
	if ( nullptr == engine )
	{
		std::cout << "Failed to get the engine API" << std::endl;
		return 3;
	}

	if ( !engine->Init( argc, argv ) )
	{
		std::cout << "Failed to initialise the engine" << std::endl;
		return 4;
	}

	while ( engine->RunFrame() )
	{
		
	}

	engine->Shutdown( "normal shutdown" );

	std::cout << "Have a nice day." << std::endl;

	return 0;
}
