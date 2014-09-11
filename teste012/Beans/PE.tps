<?xml version="1.0" encoding="UTF-8"?>
<TypesAndGlobals>
  <Types>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePinModelInputOutputDirection</Name>
      <Items lines_count="3">
        <Line>&lt;Automatic&gt;</Line>
        <Line>Input</Line>
        <Line>Output</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeMEMORYTYPE</Name>
      <Items lines_count="4">
        <Line>RAM</Line>
        <Line>ROM</Line>
        <Line>FLASH</Line>
        <Line>EEPROM</Line>
      </Items>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typeMEMORY_RAMROM</Name>
      <Items lines_count="2">
        <Line>RAM</Line>
        <Line>ROM</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeCMEMMODEL</Name>
      <Items lines_count="4">
        <Line>SMALL</Line>
        <Line>MEDIUM</Line>
        <Line>COMPACT</Line>
        <Line>LARGE</Line>
      </Items>
      <Hints lines_count="4">
        <Line>Small model</Line>
        <Line>Medium model</Line>
        <Line>Compact model</Line>
        <Line>Large model</Line>
      </Hints>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typeBoolean</Name>
      <Items lines_count="2">
        <Line>TRUE</Line>
        <Line>FALSE</Line>
      </Items>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typeYesNo</Name>
      <Items lines_count="2">
        <Line>yes</Line>
        <Line>no</Line>
      </Items>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typeMethod</Name>
      <Items lines_count="2">
        <Line>generate code</Line>
        <Line>don't generate code</Line>
      </Items>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typeINCLUDE</Name>
      <Items lines_count="2">
        <Line>include</Line>
        <Line>do not include</Line>
      </Items>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typeEnaDis</Name>
      <Items lines_count="2">
        <Line>Enabled</Line>
        <Line>Disabled</Line>
      </Items>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typeSM_EnaDis</Name>
      <Items lines_count="2">
        <Line>This component enabled</Line>
        <Line>This component disabled</Line>
      </Items>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typeOptimization</Name>
      <Items lines_count="2">
        <Line>speed</Line>
        <Line>code size</Line>
      </Items>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typeOptimalization</Name>
      <Items lines_count="2">
        <Line>speed</Line>
        <Line>code size</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePULL</Name>
      <Items lines_count="6">
        <Line>no pull resistor</Line>
        <Line>pull up</Line>
        <Line>pull down</Line>
        <Line>pull up or no pull</Line>
        <Line>pull down or no pull</Line>
        <Line>autoselected pull</Line>
      </Items>
      <Hints lines_count="6">
        <Line>Input without pull resistor is required</Line>
        <Line>Input with pull-up resistor is required</Line>
        <Line>Input with pull-down resistor is required</Line>
        <Line>Input with pull-up resistor is preferred, but no-pull is acceptable</Line>
        <Line>Input with pull-down resistor is preferred, but no-pull is acceptable</Line>
        <Line>There are no special requirements for pull resistors</Line>
      </Hints>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeUNUSED_IO_INIT</Name>
      <Items lines_count="3">
        <Line>No initialization</Line>
        <Line>Input</Line>
        <Line>Output</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePULL_INIT</Name>
      <Items lines_count="4">
        <Line>no initialization</Line>
        <Line>no pull</Line>
        <Line>pull up</Line>
        <Line>pull down</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeODE</Name>
      <Items lines_count="3">
        <Line>push-pull</Line>
        <Line>open drain</Line>
        <Line>open drain with pull-up</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeODE_INIT</Name>
      <Items lines_count="4">
        <Line>no initialization</Line>
        <Line>push-pull</Line>
        <Line>open drain</Line>
        <Line>open drain with pull-up</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeOUTVALUE_INIT</Name>
      <Items lines_count="3">
        <Line>no initialization</Line>
        <Line>0</Line>
        <Line>1</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeEDGE</Name>
      <Items lines_count="6">
        <Line>rising or falling edge</Line>
        <Line>rising edge</Line>
        <Line>falling edge</Line>
        <Line>both edges</Line>
        <Line>high level</Line>
        <Line>low level</Line>
      </Items>
      <Hints lines_count="6">
        <Line>One of the edge types will be selected: rising or falling</Line>
        <Line>Rising edge required</Line>
        <Line>Falling edge required</Line>
        <Line>Both edges (rising or falling)</Line>
        <Line>High level of the signal</Line>
        <Line>Low level of the signal</Line>
      </Hints>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeEDGEclk</Name>
      <Items lines_count="4">
        <Line>rising or falling edge</Line>
        <Line>rising edge</Line>
        <Line>falling edge</Line>
        <Line>both edges</Line>
      </Items>
      <Hints lines_count="4">
        <Line>One of the following edge type will be selected: rising or falling</Line>
        <Line>Rising edge required</Line>
        <Line>Falling edge required</Line>
        <Line>Both edges (rising and falling) required</Line>
      </Hints>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeDIR</Name>
      <Items lines_count="3">
        <Line>Input</Line>
        <Line>Output</Line>
        <Line>Input/Output</Line>
      </Items>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typeINPUTOUTPUT</Name>
      <Items lines_count="2">
        <Line>Input</Line>
        <Line>Output</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePARITY</Name>
      <Items lines_count="5">
        <Line>none</Line>
        <Line>hardware odd</Line>
        <Line>hardware even</Line>
        <Line>odd (hw or sw)</Line>
        <Line>even (hw or sw)</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePARITY9</Name>
      <Items lines_count="8">
        <Line>none</Line>
        <Line>hardware odd</Line>
        <Line>hardware even</Line>
        <Line>odd (hw or sw)</Line>
        <Line>even (hw or sw)</Line>
        <Line>wake-up (hw or sw)</Line>
        <Line>hardware wake-up</Line>
        <Line>wake-up master (hw or sw)</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeSTOPBIT</Name>
      <Items lines_count="3">
        <Line>1</Line>
        <Line>1.5</Line>
        <Line>2</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeWORDWIDTH</Name>
      <Items lines_count="6">
        <Line>4 bits</Line>
        <Line>5 bits</Line>
        <Line>6 bits</Line>
        <Line>7 bits</Line>
        <Line>8 bits</Line>
        <Line>9 bits</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeRUNTIMESETTING</Name>
      <Items lines_count="3">
        <Line>none</Line>
        <Line>specified values</Line>
        <Line>from limits</Line>
      </Items>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typeRUNTIMEBAUDSET</Name>
      <Items lines_count="2">
        <Line>none</Line>
        <Line>specified values</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePE_REGISTERVAL</Name>
      <Items lines_count="2">
        <Line>undefined value</Line>
        <Line>read value</Line>
      </Items>
    </Type>
    <Type>
      <Type>TBoolSpec</Type>
      <Name>typePE_USEDPERIPHERY</Name>
      <Items lines_count="2">
        <Line>Managed by user code</Line>
        <Line>Managed by generated code</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePE_REGISTERBITVAL</Name>
      <Items lines_count="1">
        <Line>?</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePE_REGISTERBITVAL_01</Name>
      <Items lines_count="2">
        <Line>0</Line>
        <Line>1</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeGenInitCode</Name>
      <Items lines_count="2">
        <Line>Generate initialization</Line>
        <Line>No initialization code</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeWatchDogAction</Name>
      <Items lines_count="3">
        <Line>Reset CPU</Line>
        <Line>Non maskable interrupt</Line>
        <Line>Output to pin</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeADresolution</Name>
      <Items lines_count="6">
        <Line>Autoselect</Line>
        <Line>8 bits</Line>
        <Line>10 bits</Line>
        <Line>12 bits</Line>
        <Line>14 bits</Line>
        <Line>16 bits</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptUserInterface</Name>
      <Items lines_count="2">
        <Line>Classic PE</Line>
        <Line>MCU Initialization</Line>
      </Items>
      <Hints lines_count="2">
        <Line>Classic PE User Interface without any restrictions.</Line>
        <Line>Simplified User Interface with MCU initialization components only. See PE documentation for detailed description.</Line>
      </Hints>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptEncodeDesktop</Name>
      <Items lines_count="3">
        <Line>for each project</Line>
        <Line>for each directory</Line>
        <Line>only one global</Line>
      </Items>
      <Hints lines_count="3">
        <Line>Desktop file saved to the project directory under &lt;i&gt;projectname&lt;/i&gt;.dsk</Line>
        <Line>Desktop file saved to the project directory under CpuExpert.dsk</Line>
        <Line>Desktop file saved to PE config directory</Line>
      </Hints>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptNewBeanInConfig</Name>
      <Items lines_count="3">
        <Line>in all configurations</Line>
        <Line>in active configuration only</Line>
        <Line>always ask</Line>
      </Items>
      <Hints lines_count="3">
        <Line>Enable new component in all existing project configurations.</Line>
        <Line>Enable new component in selected project configuration only. The component will be disabled in other existing configurations.</Line>
        <Line>Always ask for configurations, where the component will be enabled.</Line>
      </Hints>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptCpuBitmapDisplay</Name>
      <Items lines_count="2">
        <Line>stretched</Line>
        <Line>tiled</Line>
      </Items>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptUserModuleUpdate</Name>
      <Items lines_count="4">
        <Line>do not change</Line>
        <Line>prompt to overwrite</Line>
        <Line>always overwrite</Line>
        <Line>smart update (recommended)</Line>
      </Items>
      <Hints lines_count="4">
        <Line>Do not change user modules.</Line>
        <Line>Always confirm to overwrite user modules. User changes are not preserved.</Line>
        <Line>Always overwrite user modules. User changes are not preserved.</Line>
        <Line>Smart update - updates modules' and events' names, removes imports that were removed from project, adds new imports.</Line>
      </Hints>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptMainEventModuleUpdate</Name>
      <Items lines_count="5">
        <Line>do not change</Line>
        <Line>prompt to overwrite</Line>
        <Line>always overwrite</Line>
        <Line>smart update (recommended)</Line>
        <Line>do not generate</Line>
      </Items>
      <Hints lines_count="5">
        <Line>Do not change user modules.</Line>
        <Line>Always confirm to overwrite user modules. User changes are not preserved.</Line>
        <Line>Always overwrite user modules. User changes are not preserved.</Line>
        <Line>Smart update - updates modules' and events' names, removes imports that were removed from project, adds new imports, adds new events into event modules.</Line>
        <Line>Do not generate the user module.</Line>
      </Hints>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptDestLanguage</Name>
      <Items lines_count="0"/>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptDestDebugger</Name>
      <Items lines_count="0"/>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptDestCompiler</Name>
      <Items lines_count="0"/>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptHighNumFormat</Name>
      <Items lines_count="0"/>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptLowNumFormat</Name>
      <Items lines_count="0"/>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typePEoptIVTtype</Name>
      <Items lines_count="2">
        <Line>generate into ROM</Line>
        <Line>generate into RAM</Line>
      </Items>
      <Hints lines_count="2">
        <Line>Generate interrupt vector table into ROM.</Line>
        <Line>Generate interrupt vector table into RAM. In this mode it is possible to select interrupt vector handlers in application run-time (using CPU component methods), but it is not possible to change interrupt vector handlers used by components.</Line>
      </Hints>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeOpenDrain_Init</Name>
      <Items lines_count="2">
        <Line>push-pull</Line>
        <Line>open drain</Line>
      </Items>
      <Defines lines_count="2">
        <Line>NO_ODE</Line>
        <Line>ODE</Line>
      </Defines>
    </Type>
    <Type>
      <Type>TEnumSpec</Type>
      <Name>typeUtilizeResetValues</Name>
      <Items lines_count="3">
        <Line>default</Line>
        <Line>no</Line>
        <Line>yes</Line>
      </Items>
      <Hints lines_count="3">
        <Line>After-reset initialization is controlled by the active generator configuration setting.</Line>
        <Line>Complete initialization will be generated. Active generator configuration setting is overridden.</Line>
        <Line>Generated code will not modify registers, if the initialization value is the same as after-reset value. Active generator configuration setting is overridden.</Line>
      </Hints>
      <Defines lines_count="3">
        <Line>default</Line>
        <Line>no</Line>
        <Line>yes</Line>
      </Defines>
    </Type>
  </Types>
  <GlobalItemList>
    <GlobalItem>
      <Type>TDrctItem</Type>
      <Name>Always_OutputDir</Name>
      <Symbol>_PE_OutputDir</Symbol>
      <TypeSpec>typeDIR</TypeSpec>
      <Hint/>
      <ItemLevel>BASIC</ItemLevel>
      <EditLine>Y</EditLine>
      <TypeSpecNameChangeAble>N</TypeSpecNameChangeAble>
      <DefaultIndex>1</DefaultIndex>
      <TextValueIndex>Y</TextValueIndex>
      <RuntimeProperty>N</RuntimeProperty>
      <CanDelete>N</CanDelete>
      <IconPopup>N</IconPopup>
    </GlobalItem>
    <GlobalItem>
      <Type>TDrctItem</Type>
      <Name>Always_InputDir</Name>
      <Symbol>_PE_InputDir</Symbol>
      <TypeSpec>typeDIR</TypeSpec>
      <Hint/>
      <ItemLevel>BASIC</ItemLevel>
      <EditLine>Y</EditLine>
      <TypeSpecNameChangeAble>N</TypeSpecNameChangeAble>
      <DefaultIndex>0</DefaultIndex>
      <TextValueIndex>Y</TextValueIndex>
      <RuntimeProperty>N</RuntimeProperty>
      <CanDelete>N</CanDelete>
      <IconPopup>N</IconPopup>
    </GlobalItem>
    <GlobalItem>
      <Type>TBoolItem</Type>
      <Name>Always_False</Name>
      <Symbol>_PE_False</Symbol>
      <TypeSpec>typeBoolean</TypeSpec>
      <Hint/>
      <ItemLevel>BASIC</ItemLevel>
      <EditLine>N</EditLine>
      <TypeSpecNameChangeAble>N</TypeSpecNameChangeAble>
      <DefaultIndex>1</DefaultIndex>
      <TextValueIndex>Y</TextValueIndex>
      <RuntimeProperty>N</RuntimeProperty>
      <CanDelete>N</CanDelete>
      <IconPopup>N</IconPopup>
      <DefaultValue>N</DefaultValue>
      <Popup>N</Popup>
    </GlobalItem>
    <GlobalItem>
      <Type>TBoolItem</Type>
      <Name>Always_True</Name>
      <Symbol>_PE_True</Symbol>
      <TypeSpec>typeBoolean</TypeSpec>
      <Hint/>
      <ItemLevel>BASIC</ItemLevel>
      <EditLine>N</EditLine>
      <TypeSpecNameChangeAble>N</TypeSpecNameChangeAble>
      <DefaultIndex>0</DefaultIndex>
      <TextValueIndex>Y</TextValueIndex>
      <RuntimeProperty>N</RuntimeProperty>
      <CanDelete>N</CanDelete>
      <IconPopup>N</IconPopup>
      <DefaultValue>Y</DefaultValue>
      <Popup>N</Popup>
    </GlobalItem>
    <GlobalItem>
      <Type>TEdgeItem</Type>
      <Name>Falling_Edge</Name>
      <Symbol>_PE_FallingEdge</Symbol>
      <TypeSpec>typeEDGE</TypeSpec>
      <Hint/>
      <ItemLevel>BASIC</ItemLevel>
      <EditLine>N</EditLine>
      <TypeSpecNameChangeAble>N</TypeSpecNameChangeAble>
      <DefaultIndex>2</DefaultIndex>
      <TextValueIndex>Y</TextValueIndex>
      <RuntimeProperty>N</RuntimeProperty>
      <CanDelete>N</CanDelete>
      <IconPopup>N</IconPopup>
    </GlobalItem>
    <GlobalItem>
      <Type>TEdgeItem</Type>
      <Name>Rising_Edge</Name>
      <Symbol>_PE_RisingEdge</Symbol>
      <TypeSpec>typeEDGE</TypeSpec>
      <Hint/>
      <ItemLevel>BASIC</ItemLevel>
      <EditLine>N</EditLine>
      <TypeSpecNameChangeAble>N</TypeSpecNameChangeAble>
      <DefaultIndex>1</DefaultIndex>
      <TextValueIndex>Y</TextValueIndex>
      <RuntimeProperty>N</RuntimeProperty>
      <CanDelete>N</CanDelete>
      <IconPopup>N</IconPopup>
    </GlobalItem>
  </GlobalItemList>
</TypesAndGlobals>
