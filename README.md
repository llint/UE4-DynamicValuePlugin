# UE4-DynamicValuePlugin

The DynamicValuePlugin contains support for DynamicValue/Struct in both C++ and BP, as well as StringToDynamicValueMap to add hash map support to BP.

Currently all the UE4 basic BP types are supported as DynamicValue; in addition, array and struct are also supported as DynamicValues, in a recursive fashion.

With the support of DynamicValue, heterogeneous DynamicValue arrays (normal array of DynamicValues) are made available.

Support is also added to convert a JSON object string to a DynamicStruct directly.

MakeDynamicValueXxx BP functions are provided to create the concrete DynamicValueXxx instances.

Make sure that there is a top level BP varialbe to hold the reference to the created top level DynamicValue/Struct object (as a result of MakeDynamicValueXxx or ParseJsonString); however, any sub-DynamicValue/Struct doesn't have to be referenced explicitly due to the normal UE4 object reference graph mechanism. The C++ code makes sure that sub-objects are referenced properly.

All the BP usage examples are residing inside the project's BP_GameMode Blueprint.

Copy Plugins/DynamicValuePlugin to your project root directory to use the DynamicValues. Also, make sure the DynamicValuePlugin is enabled.
