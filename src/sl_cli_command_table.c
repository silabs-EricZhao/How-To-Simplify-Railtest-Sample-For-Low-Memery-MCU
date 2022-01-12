/***************************************************************************//**
 * @file sl_cli_command_table.c
 * @brief Declarations of relevant command structs for cli framework.
 * @version x.y.z
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#include <stdlib.h>

#include "sl_cli_config.h"
#include "sl_cli_command.h"
#include "sl_cli_arguments.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *****************************   TEMPLATED FILE   ******************************
 ******************************************************************************/

/*******************************************************************************
 * Example syntax (.slcc or .slcp) for populating this file:
 *
 *   template_contribution:
 *     - name: cli_command          # Register a command
 *       value:
 *         name: status             # Name of command
 *         handler: status_command  # Function to be called. Must be defined
 *         help: "Prints status"    # Optional help description
 *         shortcuts:               # Optional shorcut list
 *           - name: st
 *         argument:                # Argument list, if apliccable
 *           - type: uint8          # Variable type
 *             help: "Channel"      # Optional description
 *           - type: string
 *             help: "Text"
 *     - name: cli_group            # Register a group
 *       value:
 *         name: shell              # Group name
 *         help: "Shell commands"   # Optional help description
 *         shortcuts:               # Optional shorcuts
 *           - name: sh
 *     - name: cli_command
 *       value:
 *         name: repeat
 *         handler: repeat_cmd
 *         help: "Repeat commands"
 *         shortcuts:
 *           - name: r
 *           - name: rep
 *         group: shell            # Associate command with group
 *         argument:
 *           - type: string
 *             help: "Text"
 *           - type: additional
 *             help: "More text"
 *
 * For subgroups, an optional unique id can be used to allow a particular name to
 * be used more than once. In the following case, from the command line the
 * following commands are available:
 *
 * >  root_1 shell status
 * >  root_2 shell status
 *
 *     - name: cli_group            # Register a group
 *       value:
 *         name: root_1             # Group name
 *
 *     - name: cli_group            # Register a group
 *       value:
 *         name: root_2             # Group name
 *
 *    - name: cli_group             # Register a group
 *       value:
 *         name: shell              # Group name
 *         id: shell_root_1         # Optional unique id for group
 *         group: root_1            # Add group to root_1 group
 *
 *    - name: cli_group             # Register a group
 *       value:
 *         name: shell              # Group name
 *         id: shell_root_2         # Optional unique id for group
 *         group: root_2            # Add group to root_1 group
 *
 *    - name: cli_command           # Register a command
 *       value:
 *         name: status
 *         handler: status_1
 *         group: shell_root_1      # id of subgroup
 *
 *    - name: cli_command           # Register a command
 *       value:
 *         name: status
 *         handler: status_2
 *         group: shell_root_2      # id of subgroup
 *
 ******************************************************************************/
#define RAIL_LIGHTWEIGHT
// Provide function declarations
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void setEventConfig(sl_cli_command_arg_t *arguments);
#endif
void resetCounters(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void setPeripheralEnable(sl_cli_command_arg_t *arguments);
void setNotifications(sl_cli_command_arg_t *arguments);
void getLogLevels(sl_cli_command_arg_t *arguments);
#endif
void getVersion(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void getVersionVerbose(sl_cli_command_arg_t *arguments);
void setPtiProtocol(sl_cli_command_arg_t *arguments);
void getPti(sl_cli_command_arg_t *arguments);
void setPrintingEnable(sl_cli_command_arg_t *arguments);
#endif
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void rx(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void rxAt(sl_cli_command_arg_t *arguments);
#endif
void setRxOptions(sl_cli_command_arg_t *arguments);
void tx(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void txWithOptions(sl_cli_command_arg_t *arguments);
void txAfterRx(sl_cli_command_arg_t *arguments);
#endif
void configTxOptions(sl_cli_command_arg_t *arguments);
void setFixedLength(sl_cli_command_arg_t *arguments);
void setPower(sl_cli_command_arg_t *arguments);
void getPower(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void setPowerConfig(sl_cli_command_arg_t *arguments);
void getPowerConfig(sl_cli_command_arg_t *arguments);
void getPowerLimits(sl_cli_command_arg_t *arguments);
void enablePaAutoMode(sl_cli_command_arg_t *arguments);
void configPaAutoMode(sl_cli_command_arg_t *arguments);
void sweepTxPower(sl_cli_command_arg_t *arguments);
void offsetLqi(sl_cli_command_arg_t *arguments);
#endif
void getRssi(sl_cli_command_arg_t *arguments);

#ifndef RAIL_LIGHTWEIGHT
void sweepPower(sl_cli_command_arg_t *arguments);
void startAvgRssi(sl_cli_command_arg_t *arguments);
void getAvgRssi(sl_cli_command_arg_t *arguments);
#endif
void setTxTone(sl_cli_command_arg_t *arguments);
void setTxStream(sl_cli_command_arg_t *arguments);
void getStatus(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void fifoStatus(sl_cli_command_arg_t *arguments);
void setTxHoldOff(sl_cli_command_arg_t *arguments);
#endif
void setTxDelay(sl_cli_command_arg_t *arguments);
void getTxDelay(sl_cli_command_arg_t *arguments);
void setTxPayload(sl_cli_command_arg_t *arguments);
void setTxPayloadQuiet(sl_cli_command_arg_t *arguments);
void setTxLength(sl_cli_command_arg_t *arguments);
void printTxPacket(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void peekRx(sl_cli_command_arg_t *arguments);
void getTime(sl_cli_command_arg_t *arguments);
void setTime(sl_cli_command_arg_t *arguments);
void dataConfig(sl_cli_command_arg_t *arguments);
void setRxFifo(sl_cli_command_arg_t *arguments);
void setTxFifoThreshold(sl_cli_command_arg_t *arguments);
void setRxFifoThreshold(sl_cli_command_arg_t *arguments);
void fifoModeTestOptions(sl_cli_command_arg_t *arguments);
void rxFifoManualRead(sl_cli_command_arg_t *arguments);
void txFifoManualLoad(sl_cli_command_arg_t *arguments);
void fifoReset(sl_cli_command_arg_t *arguments);
void abortRxPacket(sl_cli_command_arg_t *arguments);
void printTxAcks(sl_cli_command_arg_t *arguments);
void configRxChannelHopping(sl_cli_command_arg_t *arguments);
void enableRxChannelHopping(sl_cli_command_arg_t *arguments);
void configChannelHoppingOptions(sl_cli_command_arg_t *arguments);
void configChannelHoppingMulti(sl_cli_command_arg_t *arguments);
void getChannelHoppingRssi(sl_cli_command_arg_t *arguments);
void spectrumAnalyzer(sl_cli_command_arg_t *arguments);
void configRxDutyCycle(sl_cli_command_arg_t *arguments);
void enableRxDutyCycle(sl_cli_command_arg_t *arguments);
void setTxAltPreambleLen(sl_cli_command_arg_t *arguments);
void configSyncWords(sl_cli_command_arg_t *arguments);
void getSyncWords(sl_cli_command_arg_t *arguments);
void printRxErrors(sl_cli_command_arg_t *arguments);
void printRxFreqOffsets(sl_cli_command_arg_t *arguments);
void printDataRates(sl_cli_command_arg_t *arguments);
void stopInfinitePreambleTx(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void sleep(sl_cli_command_arg_t *arguments);
void rfSense(sl_cli_command_arg_t *arguments);
void configRfSenseSelectiveOokWakeupPhy(sl_cli_command_arg_t *arguments);
void setRfSenseTxPayload(sl_cli_command_arg_t *arguments);
#endif
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void setAddressFilterConfig(sl_cli_command_arg_t *arguments);
void setAddressFilter(sl_cli_command_arg_t *arguments);
void getAddressFilter(sl_cli_command_arg_t *arguments);
void printAddresses(sl_cli_command_arg_t *arguments);
void setAddress(sl_cli_command_arg_t *arguments);
void setAddressMask(sl_cli_command_arg_t *arguments);
void enableAddress(sl_cli_command_arg_t *arguments);
#endif
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void startPerMode(sl_cli_command_arg_t *arguments);
void getPerStats(sl_cli_command_arg_t *arguments);
void berConfigSet(sl_cli_command_arg_t *arguments);
void berRx(sl_cli_command_arg_t *arguments);
void berStatusGet(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void setLbtMode(sl_cli_command_arg_t *arguments);
void getLbtParams(sl_cli_command_arg_t *arguments);
void setLbtParams(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void ieee802154Enable(sl_cli_command_arg_t *arguments);
void config2p4Ghz802154(sl_cli_command_arg_t *arguments);
void config863Mhz802154(sl_cli_command_arg_t *arguments);
void config915Mhz802154(sl_cli_command_arg_t *arguments);
void ieee802154SetE(sl_cli_command_arg_t *arguments);
void ieee802154SetG(sl_cli_command_arg_t *arguments);
void ieee802154SetFpMode(sl_cli_command_arg_t *arguments);
void ieee802154AcceptFrames(sl_cli_command_arg_t *arguments);
void ieee802154SetPromiscuousMode(sl_cli_command_arg_t *arguments);
void ieee802154SetPanCoordinator(sl_cli_command_arg_t *arguments);
void ieee802154SetPanId(sl_cli_command_arg_t *arguments);
void ieee802154SetShortAddress(sl_cli_command_arg_t *arguments);
void ieee802154SetLongAddress(sl_cli_command_arg_t *arguments);
void ieee802154SetAddresses(sl_cli_command_arg_t *arguments);
void ieee802154SetDataReqLatency(sl_cli_command_arg_t *arguments);
#endif
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void bleEnable(sl_cli_command_arg_t *arguments);
void bleStatus(sl_cli_command_arg_t *arguments);
void bleSetChannelParams(sl_cli_command_arg_t *arguments);
void blePhySwitchToRx(sl_cli_command_arg_t *arguments);
void bleAdvertisingConfig(sl_cli_command_arg_t *arguments);
void bleSet1MbpsPhy(sl_cli_command_arg_t *arguments);
void bleSet2MbpsPhy(sl_cli_command_arg_t *arguments);
void bleSetCoding(sl_cli_command_arg_t *arguments);
void bleSetSimulscan(sl_cli_command_arg_t *arguments);
#endif
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void zwaveEnable(sl_cli_command_arg_t *arguments);
void zwaveStatus(sl_cli_command_arg_t *arguments);
void zwaveSetRegion(sl_cli_command_arg_t *arguments);
void zwaveGetRegion(sl_cli_command_arg_t *arguments);
void zwaveListRegions(sl_cli_command_arg_t *arguments);
void zwaveGetBaudRate(sl_cli_command_arg_t *arguments);
void zwaveSetNodeId(sl_cli_command_arg_t *arguments);
void zwaveSetHomeId(sl_cli_command_arg_t *arguments);
void zwaveConfigureOptions(sl_cli_command_arg_t *arguments);
void zwaveSetLowPowerLevel(sl_cli_command_arg_t *arguments);
void zwaveGetLowPowerLevel(sl_cli_command_arg_t *arguments);
void zwaveReceiveBeam(sl_cli_command_arg_t *arguments);
void mfmEnable(sl_cli_command_arg_t *arguments);
void mfmStatus(sl_cli_command_arg_t *arguments);
#endif
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void setTimer(sl_cli_command_arg_t *arguments);
void timerCancel(sl_cli_command_arg_t *arguments);
void printTimerStats(sl_cli_command_arg_t *arguments);
void enableMultiTimer(sl_cli_command_arg_t *arguments);
void setMultiTimer(sl_cli_command_arg_t *arguments);
void multiTimerCancel(sl_cli_command_arg_t *arguments);
void printMultiTimerStats(sl_cli_command_arg_t *arguments);
void delayUs(sl_cli_command_arg_t *arguments);
#endif
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void autoAckConfig(sl_cli_command_arg_t *arguments);
void autoAckDisable(sl_cli_command_arg_t *arguments);
void setAckPayload(sl_cli_command_arg_t *arguments);
void setAckLength(sl_cli_command_arg_t *arguments);
void printAckPacket(sl_cli_command_arg_t *arguments);
void getAutoAck(sl_cli_command_arg_t *arguments);
void autoAckPause(sl_cli_command_arg_t *arguments);
void setTxAckOptions(sl_cli_command_arg_t *arguments);
#endif
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void setGpioOutPin(sl_cli_command_arg_t *arguments);
#endif
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
void cliSeparatorHack(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void getConfigIndex(sl_cli_command_arg_t *arguments);
void setConfigIndex(sl_cli_command_arg_t *arguments);
#endif
void setCtune(sl_cli_command_arg_t *arguments);
void getCtune(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void setCtuneDelta(sl_cli_command_arg_t *arguments);
void getCtuneDelta(sl_cli_command_arg_t *arguments);
void setPaCtune(sl_cli_command_arg_t *arguments);
void enablePaCal(sl_cli_command_arg_t *arguments);
void setDebugSignal(sl_cli_command_arg_t *arguments);
void setDebugMode(sl_cli_command_arg_t *arguments);
void setFrequency(sl_cli_command_arg_t *arguments);
void setDirectMode(sl_cli_command_arg_t *arguments);
void setDirectTx(sl_cli_command_arg_t *arguments);
void txCancel(sl_cli_command_arg_t *arguments);
void startThermistorMeasurement(sl_cli_command_arg_t *arguments);
void getThermistorImpedance(sl_cli_command_arg_t *arguments);
void getRandom(sl_cli_command_arg_t *arguments);
void setTxUnderflow(sl_cli_command_arg_t *arguments);
void setRxOverflow(sl_cli_command_arg_t *arguments);
void setCalibrations(sl_cli_command_arg_t *arguments);
void setTxTransitions(sl_cli_command_arg_t *arguments);
void setRxTransitions(sl_cli_command_arg_t *arguments);
void getTxTransitions(sl_cli_command_arg_t *arguments);
void getRxTransitions(sl_cli_command_arg_t *arguments);
void setNextTxRepeat(sl_cli_command_arg_t *arguments);
void setNextBleTxRepeat(sl_cli_command_arg_t *arguments);
void setTxTimePos(sl_cli_command_arg_t *arguments);
void setRxTimePos(sl_cli_command_arg_t *arguments);
void setTimings(sl_cli_command_arg_t *arguments);
void forceAssert(sl_cli_command_arg_t *arguments);
void getAppMode(sl_cli_command_arg_t *arguments);
void getRadioState(sl_cli_command_arg_t *arguments);
void verifyRadio(sl_cli_command_arg_t *arguments);
#endif
void getChannel(sl_cli_command_arg_t *arguments);
void setChannel(sl_cli_command_arg_t *arguments);
void resetChip(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void CI_writeRmrStructure(sl_cli_command_arg_t *arguments);
void CI_updateConfigurationPointer(sl_cli_command_arg_t *arguments);
void CI_reconfigureModem(sl_cli_command_arg_t *arguments);
void configPrintEvents(sl_cli_command_arg_t *arguments);
void printChipFeatures(sl_cli_command_arg_t *arguments);
#endif
void getMemWord(sl_cli_command_arg_t *arguments);
void setMemWord(sl_cli_command_arg_t *arguments);
#ifndef RAIL_LIGHTWEIGHT
void throughput(sl_cli_command_arg_t *arguments);
void setRssiOffset(sl_cli_command_arg_t *arguments);
void getRssiOffset(sl_cli_command_arg_t *arguments);
void txAtTime(sl_cli_command_arg_t *arguments);
void setFreqOffset(sl_cli_command_arg_t *arguments);
void holdRx(sl_cli_command_arg_t *arguments);
void wait(sl_cli_command_arg_t *arguments);
void clearScript(sl_cli_command_arg_t *arguments);
void printScript(sl_cli_command_arg_t *arguments);
void enterScript(sl_cli_command_arg_t *arguments);
void runScript(sl_cli_command_arg_t *arguments);
void setRetimeOption(sl_cli_command_arg_t *arguments);
void cli_ant_div_set_tx_antenna_mode(sl_cli_command_arg_t *arguments);
void cli_ant_div_get_tx_antenna_mode(sl_cli_command_arg_t *arguments);
void cli_ant_div_get_tx_antenna_selected(sl_cli_command_arg_t *arguments);
void cli_ant_div_toggle_tx_antenna(sl_cli_command_arg_t *arguments);
void cli_ant_div_set_rx_antenna_mode(sl_cli_command_arg_t *arguments);
void cli_ant_div_get_rx_antenna_mode(sl_cli_command_arg_t *arguments);
void cli_ant_div_get_phy_select(sl_cli_command_arg_t *arguments);
#endif
// Command structs. Names are in the format : cli_cmd_{command group name}_{command name}
// In order to support hyphen in command and group name, every occurence of it while
// building struct names will be replaced by "_hyphen_"
static const sl_cli_command_info_t cli_cmd___________________________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______Application_Configuration____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__setEventConfig = \
  SL_CLI_COMMAND(setEventConfig,
                 "Control RAIL events.",
                  "eventsMask<31:0>" SL_CLI_UNIT_SEPARATOR "eventsValues<31:0>" SL_CLI_UNIT_SEPARATOR "eventsMask<63:32>\n                    [uint32opt] eventsValues<63:32>" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd__resetCounters = \
  SL_CLI_COMMAND(resetCounters,
                 "Resets the TX and RX counters.",
                  "",
                 {SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__setPeripheralEnable = \
  SL_CLI_COMMAND(setPeripheralEnable,
                 "Control LEDs and LCD peripherals.",
                  "[0=Disable] 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setNotifications = \
  SL_CLI_COMMAND(setNotifications,
                 "Control asynchronous status prints (rxPacket,txEnd,txError).",
                  "0=Disable [1=Enable]" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getLogLevels = \
  SL_CLI_COMMAND(getLogLevels,
                 "Show whether notifications or peripherals are enabled.",
                  "",
                 {SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd__getVersion = \
  SL_CLI_COMMAND(getVersion,
                 "Get version information.",
                  "",
                 {SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__getVersionVerbose = \
  SL_CLI_COMMAND(getVersionVerbose,
                 "Get verbose version information.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setPtiProtocol = \
  SL_CLI_COMMAND(setPtiProtocol,
                 "Set PTI protocol for Network Analyzer.",
                  "0=Custom 2=Thread 3=BLE 4=Connect 5=Zigbee 6=Z-Wave" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getPti = \
  SL_CLI_COMMAND(getPti,
                 "Get PTI configuration.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setPrintingEnable = \
  SL_CLI_COMMAND(setPrintingEnable,
                 "Control all printing in RAILtest, except CLI.",
                  "0=Disable [1=Enable]" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd______________________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______Receive_and_Transmit____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__rx = \
  SL_CLI_COMMAND(rx,
                 "Control receive mode.",
                  "0=Disable [1=Enable]" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__rxAt = \
  SL_CLI_COMMAND(rxAt,
                 "Configure scheduled receive.",
                  "startTimeUs" SL_CLI_UNIT_SEPARATOR "'rel'=Relative 'abs'=Absolute" SL_CLI_UNIT_SEPARATOR "endTimeUs" SL_CLI_UNIT_SEPARATOR "'rel'=Relative 'abs'=Absolute" SL_CLI_UNIT_SEPARATOR "rxTransEndSched: [0]/1\n                    [uint8opt] hardEnd: [0]/1" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_STRING, SL_CLI_ARG_UINT32, SL_CLI_ARG_STRING, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd__setRxOptions = \
  SL_CLI_COMMAND(setRxOptions,
                 "Show/Configure receive options (RAIL_RX_OPTIONs).",
                  "rxOptionsValues: bitmask of enabled options" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__tx = \
  SL_CLI_COMMAND(tx,
                 "Transmit packets with current TX options.",
                  "number of packets, 0=continuous until next 'tx 0'" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__txWithOptions = \
  SL_CLI_COMMAND(txWithOptions,
                 "Same tx command. This command is deprecated.",
                  "number of packets, 0=continuous until next 'tx 0'" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__txAfterRx = \
  SL_CLI_COMMAND(txAfterRx,
                 "Schedule a TX with specified delay after each RX.",
                  "delayUs: 0=Disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd__configTxOptions = \
  SL_CLI_COMMAND(configTxOptions,
                 "Show/Configure transmit options (RAIL_TX_OPTIONs).",
                  "txOptionsValues: bitmask of enabled options" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setFixedLength = \
  SL_CLI_COMMAND(setFixedLength,
                 "Configure fixed length packet operation.",
                  "fixedLength: payload bytes" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setPower = \
  SL_CLI_COMMAND(setPower,
                 "Set the transmit power. The radio must be IDLE.",
                  "power: deci-dBm unless 'raw' is added" SL_CLI_UNIT_SEPARATOR "'raw'=units are raw power level" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT32, SL_CLI_ARG_STRINGOPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getPower = \
  SL_CLI_COMMAND(getPower,
                 "Get the transmit power in deci-dBm.",
                  "",
                 {SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__setPowerConfig = \
  SL_CLI_COMMAND(setPowerConfig,
                 "Set transmit PA configuration.",
                  "paMode" SL_CLI_UNIT_SEPARATOR "millivolts" SL_CLI_UNIT_SEPARATOR "rampTimeUs" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getPowerConfig = \
  SL_CLI_COMMAND(getPowerConfig,
                 "Get the transmit PA configuration.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getPowerLimits = \
  SL_CLI_COMMAND(getPowerLimits,
                 "Get min and max powerLevel for a power mode.",
                  "powerMode" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__enablePaAutoMode = \
  SL_CLI_COMMAND(enablePaAutoMode,
                 "Control automatic PA selection based on the TX power level.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__configPaAutoMode = \
  SL_CLI_COMMAND(configPaAutoMode,
                 "Configure an entry in the default PA Auto Mode plugin.",
                  "entryIndex" SL_CLI_UNIT_SEPARATOR "min: deci-dBm" SL_CLI_UNIT_SEPARATOR "max: deci-dBm" SL_CLI_UNIT_SEPARATOR "RAIL_TX_POWER_MODE for this power range" SL_CLI_UNIT_SEPARATOR "Band for the PA: [0]-2" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_INT32, SL_CLI_ARG_INT32, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });


static const sl_cli_command_info_t cli_cmd__sweepTxPower = \
  SL_CLI_COMMAND(sweepTxPower,
                 "Sweep TX power for the current PA by toning at each level.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__offsetLqi = \
  SL_CLI_COMMAND(offsetLqi,
                 "Adjust the hardware's LQI value for received packets.",
                  "offset: signed value to add\n                    The resulting LQI is capped within 0..255 range." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT32, SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd__getRssi = \
  SL_CLI_COMMAND(getRssi,
                 "Get RSSI in dBm. It'll be invalid if receiver isn't ready.",
                  "[0=don't wait] 1=wait for valid RSSI if possible" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__sweepPower = \
  SL_CLI_COMMAND(sweepPower,
                 "Sweep power by toning low/high in a square wave fashion.",
                  "lowPower: deci-dBm" SL_CLI_UNIT_SEPARATOR "hiPower: deci-dBm" SL_CLI_UNIT_SEPARATOR "periodUs" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT32, SL_CLI_ARG_INT32, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__startAvgRssi = \
  SL_CLI_COMMAND(startAvgRssi,
                 "Start AGC RSSI averaging.",
                  "averageTimeUs" SL_CLI_UNIT_SEPARATOR "channel: if different than current channel" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT16OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getAvgRssi = \
  SL_CLI_COMMAND(getAvgRssi,
                 "Get AGC RSSI averaging result.",
                  "",
                 {SL_CLI_ARG_END, });
#endif

static const sl_cli_command_info_t cli_cmd__setTxTone = \
  SL_CLI_COMMAND(setTxTone,
                 "Control tone transmission.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR "antenna: [0]/1\n         [uint32opt] mode: [0]/1=phaseNoise" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTxStream = \
  SL_CLI_COMMAND(setTxStream,
                 "Control stream transmission.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR "streamMode: [1=PN9] 2=1010 3=phaseNoise 0=tone\n                    [uint32opt] antenna: [0]/1" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__status = \
  SL_CLI_COMMAND(getStatus,
                 "Print the current status counters.",
                  "",
                 {SL_CLI_ARG_END, });

#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__fifoStatus = \
  SL_CLI_COMMAND(fifoStatus,
                 "Print the current FIFO-related counters.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTxHoldOff = \
  SL_CLI_COMMAND(setTxHoldOff,
                 "Control transmit hold-off (blocking of transmits).",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd__setTxDelay = \
  SL_CLI_COMMAND(setTxDelay,
                 "Set the inter-packet delay for repeated TX.",
                  "delayMilliseconds" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getTxDelay = \
  SL_CLI_COMMAND(getTxDelay,
                 "Get the inter-packet millisecond delay for repeated TX.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTxPayload = \
  SL_CLI_COMMAND(setTxPayload,
                 "Set TX packet payload bytes for future transmits.",
                  "offset" SL_CLI_UNIT_SEPARATOR "byte0 byte1 ..." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTxPayloadQuiet = \
  SL_CLI_COMMAND(setTxPayloadQuiet,
                 "Like setTxPayload, but less verbose.",
                  "offset" SL_CLI_UNIT_SEPARATOR "byte0 byte1 ..." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTxLength = \
  SL_CLI_COMMAND(setTxLength,
                 "Set how much data to load into the TX FIFO for transmitting.\n                    Actual packet length may vary based on radio configuration.",
                  "lengthBytes" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__printTxPacket = \
  SL_CLI_COMMAND(printTxPacket,
                 "Print the current TX payload data and byte length.",
                  "",
                 {SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__peek = \
  SL_CLI_COMMAND(peekRx,
                 "Peek at the start of the receive buffer.",
                  "bytes: 1-10" SL_CLI_UNIT_SEPARATOR "offset: [0]" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getTime = \
  SL_CLI_COMMAND(getTime,
                 "Get the current RAIL time in microseconds.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTime = \
  SL_CLI_COMMAND(setTime,
                 "Set the current RAIL time.",
                  "timeUs" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__dataConfig = \
  SL_CLI_COMMAND(dataConfig,
                 "Control the data methods for TX and RX.",
                  "txMethod: 'pkt'/'fifo'" SL_CLI_UNIT_SEPARATOR "rxMethod: 'pkt'/'fifo'" SL_CLI_UNIT_SEPARATOR "rxSource: RAIL_RxDataSource_t (>0 requires fifo mode)" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_STRING, SL_CLI_ARG_STRING, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setRxFifo = \
  SL_CLI_COMMAND(setRxFifo,
                 "Set the receive buffer length.",
                  "lengthBytes: range 64-RX_BUFFER_SIZE" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTxFifoThreshold = \
  SL_CLI_COMMAND(setTxFifoThreshold,
                 "Set the TX FIFO Almost Emtpy threshold.",
                  "thresholdBytes: below which the event triggers" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setRxFifoThreshold = \
  SL_CLI_COMMAND(setRxFifoThreshold,
                 "Set the RX FIFO Almost Full threshold.",
                  "thresholdBytes: above which the event triggers" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__fifoModeTestOptions = \
  SL_CLI_COMMAND(fifoModeTestOptions,
                 "Manual control over RAILtest FIFO actions.",
                  "txFifo: 1=Manual 0=Automatic" SL_CLI_UNIT_SEPARATOR "rxFifo: 1=Manual 0=Automatic" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__rxFifoManualRead = \
  SL_CLI_COMMAND(rxFifoManualRead,
                 "Read and print bytes from receive FIFO when in manual mode.",
                  "appendedInfo: 1=include packet metadata" SL_CLI_UNIT_SEPARATOR "bytesToRead" SL_CLI_UNIT_SEPARATOR "[0=don't] 1=show timestamps with appendedInfo" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__txFifoManualLoad = \
  SL_CLI_COMMAND(txFifoManualLoad,
                 "Try to load data into available TX FIFO space.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__fifoReset = \
  SL_CLI_COMMAND(fifoReset,
                 "Reset the transmit and/or receive FIFO.",
                  "tx: 1=reset TX FIFO" SL_CLI_UNIT_SEPARATOR "rx: 1=reset RX FIFO" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__abortRxPacket = \
  SL_CLI_COMMAND(abortRxPacket,
                 "Idle the radio shortly after RX sync word detection.",
                  "abortOffsetUs" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__printTxAcks = \
  SL_CLI_COMMAND(printTxAcks,
                 "Control printing of TX ACK packets.",
                  "[0=Disable] 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__configRxHopping = \
  SL_CLI_COMMAND(configRxChannelHopping,
                 "Configure an RX Channel Hopping sequence.",
                  "channel hopMode param delayUs: a hop's config,\n                                repeat for additional hops ...\n                    Use no arguments to get Z-Wave radio config defaults." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__enableRxHopping = \
  SL_CLI_COMMAND(enableRxChannelHopping,
                 "Control RX channel hopping previously configured.",
                  "[0=Disable] 1=Enable" SL_CLI_UNIT_SEPARATOR "[0=Continue] 1=Restart sequence" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__configRxHoppingOpts = \
  SL_CLI_COMMAND(configChannelHoppingOptions,
                 "Configure options for a hop. Use configRxHopping after.",
                  "hopIndex" SL_CLI_UNIT_SEPARATOR "options" SL_CLI_UNIT_SEPARATOR "rssiThreshold: dBm for the threshold option" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_INT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__configRxMultiHop = \
  SL_CLI_COMMAND(configChannelHoppingMulti,
                 "Configure multi-sense for a hop. Use configRxHopping after.",
                  "hopIndex" SL_CLI_UNIT_SEPARATOR "syncDetectUs" SL_CLI_UNIT_SEPARATOR "preambleSenseUs" SL_CLI_UNIT_SEPARATOR "timingSenseUs" SL_CLI_UNIT_SEPARATOR "timingReSenseUs" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getRxHoppingRssi = \
  SL_CLI_COMMAND(getChannelHoppingRssi,
                 "Get the latest RSSI for a hopping channel.",
                  "hopIndex" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__spectrumAnalyzer = \
  SL_CLI_COMMAND(spectrumAnalyzer,
                 "Hop across a channel range to see the RSSI distribution.",
                  "1=Show ASCII-Art graph (non-parseable output)" SL_CLI_UNIT_SEPARATOR "minChannel: [0]-65535\n                    [uint16opt] maxChannel: 0-[65535]\n                    Channel range is limited by the PHY and by hopping's\n                    MAX_NUMBER_CHANNELS." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__configRxDutyCycle = \
  SL_CLI_COMMAND(configRxDutyCycle,
                 "Configure RX Duty Cycling of the receiver.",
                  "hopMode" SL_CLI_UNIT_SEPARATOR "parameter(s) {syncUs preamUs timingUs retimingUs}" SL_CLI_UNIT_SEPARATOR "delayUs" SL_CLI_UNIT_SEPARATOR "options\n                    [int32opt] rssiThreshold: dBm for the threshold option" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_INT32, SL_CLI_ARG_INT32, SL_CLI_ARG_INT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__enableRxDutyCycle = \
  SL_CLI_COMMAND(enableRxDutyCycle,
                 "Control RX duty cycling previously configured.",
                  "DutyCycling: 0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR "ScheduledWakeup: [0=Disable] 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTxAltPreambleLen = \
  SL_CLI_COMMAND(setTxAltPreambleLen,
                 "Set alternate TX preamble length, enabled via txOptions.",
                  "preambleBits" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__configSyncWords = \
  SL_CLI_COMMAND(configSyncWords,
                 "Set sync words and their length. The radio must be off.",
                  "bits: 2-32" SL_CLI_UNIT_SEPARATOR "syncWord1" SL_CLI_UNIT_SEPARATOR "syncWord2: [same as syncWord1]" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getSyncWords = \
  SL_CLI_COMMAND(getSyncWords,
                 "Get the sync word length in bits and value(s).",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__printRxErrors = \
  SL_CLI_COMMAND(printRxErrors,
                 "Control printing of RX error packets.",
                  "[0=Disable] 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__printRxFreqOffsets = \
  SL_CLI_COMMAND(printRxFreqOffsets,
                 "Control printing of RX frequency offsets.",
                  "[0=Disable] 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__printDataRates = \
  SL_CLI_COMMAND(printDataRates,
                 "Print the data rates of the current PHY.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__stopInfinitePream = \
  SL_CLI_COMMAND(stopInfinitePreambleTx,
                 "Stops an infinite preamble transmission.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_____________________________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______Energy_Modes_and_RF_Sensing____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__sleep = \
  SL_CLI_COMMAND(sleep,
                 "Sleep until UART input or RF Sensed (if either configured).",
                  "energyMode: 0-4[hs], for EM1P use 2 with radio on" SL_CLI_UNIT_SEPARATOR "Legacy: RfSenseUs\n                                        RfBand: 0=none,1=GHz,2=MHz,3=both\n                          or Selective: SyncwordBytes Syncword RfBand" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_STRING, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__rfsense = \
  SL_CLI_COMMAND(rfSense,
                 "Start RfSensing.",
                  "Legacy: RfSenseUs; Selective: SyncwordBytes" SL_CLI_UNIT_SEPARATOR "Legacy: RfBand: 0=none,1=GHz,2=MHz,3=both\n                          or Selective: Syncword RfBand: as above" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__configRfSenseWakeup = \
  SL_CLI_COMMAND(configRfSenseSelectiveOokWakeupPhy,
                 "Configure RFSense Selective Wakeup PHY for transmitting.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setRfSenseTxPayload = \
  SL_CLI_COMMAND(setRfSenseTxPayload,
                 "Load TX FIFO with RfSense Selective(OOK) Mode wake packet.",
                  "syncwordNumBytes: 1-4" SL_CLI_UNIT_SEPARATOR "syncWord: sent from least to most significant byte" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd___________________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______Address_Filtering____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__configAddressFilter = \
  SL_CLI_COMMAND(setAddressFilterConfig,
                 "Configure the addresss filter.",
                  "matchTable" SL_CLI_UNIT_SEPARATOR "offset0 size0 offset1 size1 ...\n                    Enter more offsets and sizes if required." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setAddressFiltering = \
  SL_CLI_COMMAND(setAddressFilter,
                 "Control address filtering.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getAddressFiltering = \
  SL_CLI_COMMAND(getAddressFilter,
                 "Get the current state of address filtering.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__printAddresses = \
  SL_CLI_COMMAND(printAddresses,
                 "Print the current address filtering addresses.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setAddress = \
  SL_CLI_COMMAND(setAddress,
                 "Set a specific filtering address value.",
                  "field: 0-1" SL_CLI_UNIT_SEPARATOR "filterIndex: 0-3" SL_CLI_UNIT_SEPARATOR "addrByte0 addrByte1 ... addrByte7" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setAddressMask = \
  SL_CLI_COMMAND(setAddressMask,
                 "Set a specific filtering address mask.",
                  "field: 0-1" SL_CLI_UNIT_SEPARATOR "bitMask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setAddressEnable = \
  SL_CLI_COMMAND(enableAddress,
                 "Control address filtering for a specific address.",
                  "field: 0-1" SL_CLI_UNIT_SEPARATOR "filterIndex: 0-3" SL_CLI_UNIT_SEPARATOR "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd____________________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______Error_Rate_Testing____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__perRx = \
  SL_CLI_COMMAND(startPerMode,
                 "Start a Packet Error Rate test. 'perRx 0 0' stops test.",
                  "number of packets" SL_CLI_UNIT_SEPARATOR "delayUs" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__perStatus = \
  SL_CLI_COMMAND(getPerStats,
                 "Get the PER test results. Also see status command.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setBerConfig = \
  SL_CLI_COMMAND(berConfigSet,
                 "Set number of bytes to receive in BER mode.",
                  "number of bytes: 0=maximum (536870911)" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__berRx = \
  SL_CLI_COMMAND(berRx,
                 "Control BER receive mode.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__berStatus = \
  SL_CLI_COMMAND(berStatusGet,
                 "Get status of current or last BER test.\n                    Status is reset by setBerConfig and berRx enable.",
                  "",
                 {SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd________________________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______Listen_Before_Talk_LBT____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setLbtMode = \
  SL_CLI_COMMAND(setLbtMode,
                 "Show/Set the LBT mode for transmits.",
                  "'off'/'csma'/'lbt'" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_STRINGOPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getLbtParams = \
  SL_CLI_COMMAND(getLbtParams,
                 "Get the current LBT parameters.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setLbtParams = \
  SL_CLI_COMMAND(setLbtParams,
                 "Set LBT parameters.",
                  "minBo" SL_CLI_UNIT_SEPARATOR "maxBo" SL_CLI_UNIT_SEPARATOR "tries" SL_CLI_UNIT_SEPARATOR "ccaThreshold" SL_CLI_UNIT_SEPARATOR "backoffUs" SL_CLI_UNIT_SEPARATOR "durationUs" SL_CLI_UNIT_SEPARATOR "timeoutUs" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_INT32, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_______________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______802_15_4_Mode____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__enable802154 = \
  SL_CLI_COMMAND(ieee802154Enable,
                 "Configure and enable 802.15.4 mode.",
                  "defaultState: 'idle'/'rx'" SL_CLI_UNIT_SEPARATOR "idleToRxUs" SL_CLI_UNIT_SEPARATOR "turnaroundTimeUs" SL_CLI_UNIT_SEPARATOR "ackTimeoutUs: to ACK's sync-detect" SL_CLI_UNIT_SEPARATOR "defaultFP: [0]/1 Frame Pending for poll ACKs" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_STRING, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_INT16, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__config2p4GHz802154 = \
  SL_CLI_COMMAND(config2p4Ghz802154,
                 "Configure the radio for 2.4 GHz 802.15.4.\n                    Use with enable802154.",
                  "antDiv: [0=Disable] 1=Enable\n                    [uint8opt] coex: [0=Disable] 1=Enable\n                    [uint8opt] fem: [0=Disable] 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__config863MHz802154 = \
  SL_CLI_COMMAND(config863Mhz802154,
                 "Configure the radio for 863 MHz 802.15.4 GB868.\n                    Use with enable802154.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__config915MHz802154 = \
  SL_CLI_COMMAND(config915Mhz802154,
                 "Configure the radio for 915 MHz 802.15.4 GB868.\n                    Use with enable802154.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__set802154e = \
  SL_CLI_COMMAND(ieee802154SetE,
                 "Configure 802.15.4E options.",
                  "RAIL_IEEE802154_EOptions_t" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__set802154g = \
  SL_CLI_COMMAND(ieee802154SetG,
                 "Configure 802.15.4G options.",
                  "RAIL_IEEE802154_GOptions_t" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__set802154FpMode = \
  SL_CLI_COMMAND(ieee802154SetFpMode,
                 "Control early and data frame pending lookup.",
                  "early:     [0=Disable] 1=Enable" SL_CLI_UNIT_SEPARATOR "dataframes:[0=Disable] 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__acceptFrames = \
  SL_CLI_COMMAND(ieee802154AcceptFrames,
                 "Control 802.15.4 frame type acceptance.",
                  "command: 0=Reject [1=Accept]" SL_CLI_UNIT_SEPARATOR "ack:    [0=Reject] 1=Accept" SL_CLI_UNIT_SEPARATOR "data:    0=Reject [1=Accept]" SL_CLI_UNIT_SEPARATOR "beacon:  0=Reject [1=Accept]" SL_CLI_UNIT_SEPARATOR "multipurpose: [0=Reject] 1=Accept" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setPromiscuousMode = \
  SL_CLI_COMMAND(ieee802154SetPromiscuousMode,
                 "Control promiscuous mode.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setPanCoordinator = \
  SL_CLI_COMMAND(ieee802154SetPanCoordinator,
                 "Control whether node is a PAN coordinator.",
                  "1=Yes 0=No" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setPanId802154 = \
  SL_CLI_COMMAND(ieee802154SetPanId,
                 "Set the PAN ID for a filtering index.",
                  "panId" SL_CLI_UNIT_SEPARATOR "filterIndex: [0]-2" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setShortAddr802154 = \
  SL_CLI_COMMAND(ieee802154SetShortAddress,
                 "Set the short address for a filtering index.",
                  "shortAddr" SL_CLI_UNIT_SEPARATOR "filterIndex: [0]-2" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setLongAddr802154 = \
  SL_CLI_COMMAND(ieee802154SetLongAddress,
                 "Set the long address for a filtering index.",
                  "longAddr_0" SL_CLI_UNIT_SEPARATOR "longAddr_1" SL_CLI_UNIT_SEPARATOR "longAddr_2" SL_CLI_UNIT_SEPARATOR "longAddr_3" SL_CLI_UNIT_SEPARATOR "longAddr_4" SL_CLI_UNIT_SEPARATOR "longAddr_5" SL_CLI_UNIT_SEPARATOR "longAddr_6" SL_CLI_UNIT_SEPARATOR "longAddr_7" SL_CLI_UNIT_SEPARATOR "filterIndex: [0]-2" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setAddresses802154 = \
  SL_CLI_COMMAND(ieee802154SetAddresses,
                 "Set all 802.15.4 address information.",
                  "panId0" SL_CLI_UNIT_SEPARATOR "shortAddr0" SL_CLI_UNIT_SEPARATOR "longAddr0\n                    [stringopt] panId1 shortAddr1 longAddr1 ..." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_STRINGOPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setDataReqLatency = \
  SL_CLI_COMMAND(ieee802154SetDataReqLatency,
                 "Set data request event processing latency.",
                  "latencyUs" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______BLE_Mode____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setBleMode = \
  SL_CLI_COMMAND(bleEnable,
                 "Control BLE mode.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getBleMode = \
  SL_CLI_COMMAND(bleStatus,
                 "Get the current BLE mode.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setBleChannelParams = \
  SL_CLI_COMMAND(bleSetChannelParams,
                 "Configure channel parameters related to BLE.",
                  "logicalChannel" SL_CLI_UNIT_SEPARATOR "accessAddr crcInit disableWhiten" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setBlePhySwitchToRx = \
  SL_CLI_COMMAND(blePhySwitchToRx,
                 "Configure BLE PhySwitchToRx parameters. RX is\n                    entered timeDeltaUs after sync word of received packet.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR "phy timeDelta physicalChannel\n                    [uint32opt] logicalChannel accessAddr crcInit\n                    [uint32opt] disableWhiten" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setBleAdvertising = \
  SL_CLI_COMMAND(bleAdvertisingConfig,
                 "Configure for BLE advertising.",
                  "advChannel: 37-39" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setBle1Mbps = \
  SL_CLI_COMMAND(bleSet1MbpsPhy,
                 "Switch to the 1Mbps BLE PHY.",
                  "0=Legacy 1=Viterbi [chip default]" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setBle2Mbps = \
  SL_CLI_COMMAND(bleSet2MbpsPhy,
                 "Switch to the 2Mbps BLE PHY.",
                  "0=Legacy 1=Viterbi [chip default]" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setBleCoding = \
  SL_CLI_COMMAND(bleSetCoding,
                 "Switch to a BLE coded PHY.",
                  "RAIL_BLE_Coding_t value" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setBleSimulscan = \
  SL_CLI_COMMAND(bleSetSimulscan,
                 "Switch to a BLE simulscan PHY.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_____________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______Z_Wave_Mode____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setZWaveMode = \
  SL_CLI_COMMAND(zwaveEnable,
                 "Show/Control Z-Wave mode.",
                  "0=Disable 1=Enable\n                    [uint8opt] optionsBitmask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getZWaveMode = \
  SL_CLI_COMMAND(zwaveStatus,
                 "Get the current Z-Wave mode.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setZWaveRegion = \
  SL_CLI_COMMAND(zwaveSetRegion,
                 "Set the Z-Wave region.",
                  "region: see listZWaveRegions" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getZWaveRegion = \
  SL_CLI_COMMAND(zwaveGetRegion,
                 "Get the current Z-Wave region.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__listZWaveRegions = \
  SL_CLI_COMMAND(zwaveListRegions,
                 "List supported Z-Wave regions.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getZWaveBaudRate = \
  SL_CLI_COMMAND(zwaveGetBaudRate,
                 "Get the baudrate of the current Z-Wave channel.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setZWaveNodeId = \
  SL_CLI_COMMAND(zwaveSetNodeId,
                 "Sets Z-Wave NodeId.",
                  "nodeId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setZWaveHomeId = \
  SL_CLI_COMMAND(zwaveSetHomeId,
                 "Sets Z-Wave HomeId and its hash.",
                  "homeId" SL_CLI_UNIT_SEPARATOR "hash" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setZWaveOptions = \
  SL_CLI_COMMAND(zwaveConfigureOptions,
                 "Configure Z-Wave options.",
                  "optionsBitmask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setZWaveLowPower = \
  SL_CLI_COMMAND(zwaveSetLowPowerLevel,
                 "Set the transmit power for low-power ACKing.",
                  "power: deci-dBm unless 'raw' is added" SL_CLI_UNIT_SEPARATOR "'raw'=units are raw power level" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT32, SL_CLI_ARG_STRINGOPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getZWaveLowPower = \
  SL_CLI_COMMAND(zwaveGetLowPowerLevel,
                 "Get the low power values (deci-dBm and raw).",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__zwaveReceiveBeam = \
  SL_CLI_COMMAND(zwaveReceiveBeam,
                 "Run the Z-Wave beam detection algorithm.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setMfmMode = \
  SL_CLI_COMMAND(mfmEnable,
                 "Set MFM mode to enabled or disabled",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR "optionsBitmask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getMfmMode = \
  SL_CLI_COMMAND(mfmStatus,
                 "Get the current MFM mod",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd____________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______RAIL_Timer____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTimer = \
  SL_CLI_COMMAND(setTimer,
                 "Set the RAIL timer timeout.",
                  "timeout: per mode" SL_CLI_UNIT_SEPARATOR "'rel'=Relative 'abs'=Absolute" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_STRING, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__timerCancel = \
  SL_CLI_COMMAND(timerCancel,
                 "Cancel the RAIL timer if it is active.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__printTimerStats = \
  SL_CLI_COMMAND(printTimerStats,
                 "Print current timer configuration.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__enableMultiTimer = \
  SL_CLI_COMMAND(enableMultiTimer,
                 "Control the multiTimer API.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setMultiTimer = \
  SL_CLI_COMMAND(setMultiTimer,
                 "Set a specific timer timeout.",
                  "timer: 0..(NUM_MULTI_TIMERS-1)" SL_CLI_UNIT_SEPARATOR "timeout: per mode" SL_CLI_UNIT_SEPARATOR "'rel'=Relative 'abs'=Absolute" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_STRING, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__multiTimerCancel = \
  SL_CLI_COMMAND(multiTimerCancel,
                 "Cancel a specific timer if it is active.",
                  "timer: 0..(NUM_MULTI_TIMERS-1)" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getMultiTimerStats = \
  SL_CLI_COMMAND(printMultiTimerStats,
                 "Get information about a specific timer.",
                  "timer: 0..(NUM_MULTI_TIMERS-1)" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__delayUs = \
  SL_CLI_COMMAND(delayUs,
                 "Do a blocking delay for a specified time.",
                  "delayUs" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______Auto_ACK_ing____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__autoAckConfig = \
  SL_CLI_COMMAND(autoAckConfig,
                 "Configure and enable auto-ACK functionality.",
                  "defaultState: 'idle'/'rx'" SL_CLI_UNIT_SEPARATOR "idleToRxUs" SL_CLI_UNIT_SEPARATOR "turnaroundTimeUs" SL_CLI_UNIT_SEPARATOR "ackTimeoutUs: to ACK's sync-detect" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_STRING, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__autoAckDisable = \
  SL_CLI_COMMAND(autoAckDisable,
                 "Disable auto-ACK. Use autoAckConfig to reenable.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setAckPayload = \
  SL_CLI_COMMAND(setAckPayload,
                 "Set the ACK payload to transmit.",
                  "offset" SL_CLI_UNIT_SEPARATOR "byte0 byte1 ..." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setAckLength = \
  SL_CLI_COMMAND(setAckLength,
                 "Set how much data to load into the TXACK FIFO.",
                  "lengthBytes" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__printAckPacket = \
  SL_CLI_COMMAND(printAckPacket,
                 "Print the current TXACK payload data and byte length.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getAutoAck = \
  SL_CLI_COMMAND(getAutoAck,
                 "Get the current state of auto-ACKing.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__autoAckPause = \
  SL_CLI_COMMAND(autoAckPause,
                 "Pause or Resume auto-ACKing",
                  "1=PauseRx 0=ResumeRx" SL_CLI_UNIT_SEPARATOR "1=PauseTx 0=ResumeTx" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTxAckOptions = \
  SL_CLI_COMMAND(setTxAckOptions,
                 "Control auto-ACK response for just the next receive.",
                  "1=cancelAck 0=sendAck" SL_CLI_UNIT_SEPARATOR "1=useTxBuf 0=useTxAckBuf" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd________________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______GPIO_Functions____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setGpioOutPin = \
  SL_CLI_COMMAND(setGpioOutPin,
                 "Set a GPIO pin data out bit.",
                  "gpioPort: start from '0' or 'a' or 'A'" SL_CLI_UNIT_SEPARATOR "gpioPin" SL_CLI_UNIT_SEPARATOR "state: 0/1" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_STRING, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd_____________________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd______Diagnostic_and_Test____ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                 "",
                  "",
                 {SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__getConfigIndex = \
  SL_CLI_COMMAND(getConfigIndex,
                 "Get the index of the current multi-PHY radio config.\n                    See the entries in *channelConfigs[]. Start with index 0.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setConfigIndex = \
  SL_CLI_COMMAND(setConfigIndex,
                 "Activate a multi-PHY radio configuration.\n                    See the entries in *channelConfigs[]. Start with index 0.",
                  "multiPhyIndex" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd__setCtune = \
  SL_CLI_COMMAND(setCtune,
                 "Set the value of HFXO CTUNE. The radio must be IDLE.",
                  "ctune" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getCtune = \
  SL_CLI_COMMAND(getCtune,
                 "Get the value of HFXO CTUNE",
                  "",
                 {SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__setCtuneDelta = \
  SL_CLI_COMMAND(setCtuneDelta,
                 "Set the value of HFXO CTUNE delta",
                  "delta" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getCtuneDelta = \
  SL_CLI_COMMAND(getCtuneDelta,
                 "Get the value of HFXO CTUNE delta",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setPaCtune = \
  SL_CLI_COMMAND(setPaCtune,
                 "Set the PACTUNE value for TX and RX.",
                  "txPaCtune" SL_CLI_UNIT_SEPARATOR "rxPaCtune" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__enablePaCal = \
  SL_CLI_COMMAND(enablePaCal,
                 "Control PA power calibration.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setDebugSignal = \
  SL_CLI_COMMAND(setDebugSignal,
                 "Configure chip specific debug output.\n                    Use 'setDebugSignal help me' for more details.",
                  "pin" SL_CLI_UNIT_SEPARATOR "signal" SL_CLI_UNIT_SEPARATOR "signalOptions" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_STRING, SL_CLI_ARG_STRING, SL_CLI_ARG_UINT16OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setDebugMode = \
  SL_CLI_COMMAND(setDebugMode,
                 "Control Debug mode which allows freqOverride.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__freqOverride = \
  SL_CLI_COMMAND(setFrequency,
                 "Set the radio frequency. Requires debug mode.",
                  "freqHz: Only small deviations from the\n                                     current configuration are supported." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__directMode = \
  SL_CLI_COMMAND(setDirectMode,
                 "Control direct mode.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__directTx = \
  SL_CLI_COMMAND(setDirectTx,
                 "Control TX in direct mode.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__txCancel = \
  SL_CLI_COMMAND(txCancel,
                 "Start a TX that will be cancelled.",
                  "delayUs: when to cancel it" SL_CLI_UNIT_SEPARATOR "stopMode: [0=RAIL_Idle] >0=RAIL_StopMode_t" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT32, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__startThermistor = \
  SL_CLI_COMMAND(startThermistorMeasurement,
                 "Configures the thermistor pin and starts a measurement.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getThermistor = \
  SL_CLI_COMMAND(getThermistorImpedance,
                 "Gets the thermistor impedance.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getRandom = \
  SL_CLI_COMMAND(getRandom,
                 "Get random data from the radio.",
                  "lengthBytes" SL_CLI_UNIT_SEPARATOR "[0=show them] 1=hide them" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTxUnderflow = \
  SL_CLI_COMMAND(setTxUnderflow,
                 "Control TX underflows by not loading the TX FIFO.",
                  "1=Force underflows 0=Disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setRxOverflow = \
  SL_CLI_COMMAND(setRxOverflow,
                 "Control RX overflows by delaying in the event handler.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR "delayUs: [0]" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setCalibrations = \
  SL_CLI_COMMAND(setCalibrations,
                 "Control calibrations.",
                  "0=Disable 1=Enable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTxTransitions = \
  SL_CLI_COMMAND(setTxTransitions,
                 "Set the TX state transitions.",
                  "txSuccess: 'idle'/'rx'" SL_CLI_UNIT_SEPARATOR "txError: 'idle'/'rx'" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_STRING, SL_CLI_ARG_STRING, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setRxTransitions = \
  SL_CLI_COMMAND(setRxTransitions,
                 "Set the RX state transitions.",
                  "rxSuccess: 'idle'/'rx'/'tx'" SL_CLI_UNIT_SEPARATOR "rxError: 'idle'/'rx'/'tx'" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_STRING, SL_CLI_ARG_STRING, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getTxTransitions = \
  SL_CLI_COMMAND(getTxTransitions,
                 "Get the TX state transitions.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getRxTransitions = \
  SL_CLI_COMMAND(getRxTransitions,
                 "Get the RX state transitions.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setNextTxRepeat = \
  SL_CLI_COMMAND(setNextTxRepeat,
                 "Set next transmit's automatic repeat count.",
                  "number of auto-repeated transmits after the first" SL_CLI_UNIT_SEPARATOR "delayUs inter-transmit or hop delay\n                    [uint32opt] channel (if hopping)\n                    repeat delayUs and channel for additional hops." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setNextBleTxRepeat = \
  SL_CLI_COMMAND(setNextBleTxRepeat,
                 "Set next transmit's automatic repeat count.",
                  "number of auto-repeated transmits after the first" SL_CLI_UNIT_SEPARATOR "delayUs inter-transmit or hop delay\n                    [uint32opt] phy railChannel logicalChannel accessAddress\n                    (a hop's config, repeat from delayUs for additional hops)" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTxTimePos = \
  SL_CLI_COMMAND(setTxTimePos,
                 "Set desired TX timestamp position.",
                  "RAIL_PacketTimePosition_t" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setRxTimePos = \
  SL_CLI_COMMAND(setRxTimePos,
                 "Set desired RX timestamp position.",
                  "RAIL_PacketTimePosition_t" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setTimings = \
  SL_CLI_COMMAND(setTimings,
                 "Set RAIL state transition timings (use -1 to keep same).",
                  "idleToRxUs" SL_CLI_UNIT_SEPARATOR "rxToTxUs" SL_CLI_UNIT_SEPARATOR "idleToTxUs" SL_CLI_UNIT_SEPARATOR "txToRxUs [0]\n                    [int32opt] rxSearchTimeoutUs [0]\n                    [int32opt] txToRxSearchTimeout [0]\n                    [int32opt] txToTx [0]" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT32, SL_CLI_ARG_INT32, SL_CLI_ARG_INT32, SL_CLI_ARG_INT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__forceAssert = \
  SL_CLI_COMMAND(forceAssert,
                 "Force a RAIL assert with the given error code.",
                  "RAIL_AssertErrorCodes_t" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getAppMode = \
  SL_CLI_COMMAND(getAppMode,
                 "Get the current RAILtest AppMode_t mode.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getRadioState = \
  SL_CLI_COMMAND(getRadioState,
                 "Get the current RAIL_RadioState_t radio state.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__verifyRadio = \
  SL_CLI_COMMAND(verifyRadio,
                 "Verify radio memory contents.",
                  "durationUs: time limit" SL_CLI_UNIT_SEPARATOR "0=Resume if previously didn't finish 1=Restart" SL_CLI_UNIT_SEPARATOR "0=current radio config 1=external radio config" SL_CLI_UNIT_SEPARATOR "0=No callback 1=Use RAILCb_ConfigVerification" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd__getChannel = \
  SL_CLI_COMMAND(getChannel,
                 "Get the current radio channel.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setChannel = \
  SL_CLI_COMMAND(setChannel,
                 "Set the radio channel.",
                  "channel" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__reset = \
  SL_CLI_COMMAND(resetChip,
                 "Perform a reboot of the chip.",
                  "",
                 {SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__writeRmrStructure = \
  SL_CLI_COMMAND(CI_writeRmrStructure,
                 "Reserved for Simplicity Studio use only.",
                  "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__updateConfigPtr = \
  SL_CLI_COMMAND(CI_updateConfigurationPointer,
                 "Reserved for Simplicity Studio use only.",
                  "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__reconfigureModem = \
  SL_CLI_COMMAND(CI_reconfigureModem,
                 "Reserved for Simplicity Studio use only.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__printEvents = \
  SL_CLI_COMMAND(configPrintEvents,
                 "Show/Configure printing of RAIL events as they occur.",
                  "printEvents<31:0> printEvents<63:32>\n                    [uint32opt] mask<31:0> mask<63:32>" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__printChipFeatures = \
  SL_CLI_COMMAND(printChipFeatures,
                 "Display RAIL features supported at compile and runtime.",
                  "",
                 {SL_CLI_ARG_END, });
#endif
static const sl_cli_command_info_t cli_cmd__getmemw = \
  SL_CLI_COMMAND(getMemWord,
                 "Read count 32-bit words starting at address.",
                  "address" SL_CLI_UNIT_SEPARATOR "count" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setmemw = \
  SL_CLI_COMMAND(setMemWord,
                 "Write 32-bit values starting at address.",
                  "address" SL_CLI_UNIT_SEPARATOR "value0 value1 ..." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT32OPT, SL_CLI_ARG_END, });
#ifndef RAIL_LIGHTWEIGHT
static const sl_cli_command_info_t cli_cmd__throughput = \
  SL_CLI_COMMAND(throughput,
                 "Throughput test.",
                  "number of packets" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setRssiOffset = \
  SL_CLI_COMMAND(setRssiOffset,
                 "Sets the RSSI offset.",
                  "offsetDbm" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__getRssiOffset = \
  SL_CLI_COMMAND(getRssiOffset,
                 "Gets the RSSI offset(s) in dBm.",
                  "[0=radio and protocol-specific] 1=radio only" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__txAt = \
  SL_CLI_COMMAND(txAtTime,
                 "Transmit a packet at a certain time.",
                  "time: per mode" SL_CLI_UNIT_SEPARATOR "['abs'=Absolute] 'rel'=Relative\n                    [stringopt] 'abort' RX if TX occurs during packet RX\n                                    otherwise TX is delayed to end of RX" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_STRINGOPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setFreqOffset = \
  SL_CLI_COMMAND(setFreqOffset,
                 "Get/Set the frequency offset adjustment.",
                  "offsetHz" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT32OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__holdRx = \
  SL_CLI_COMMAND(holdRx,
                 "Control holding of received packets.",
                  "[0=Process packets immediately] 1=Hold packets" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__wait = \
  SL_CLI_COMMAND(wait,
                 "Suspend processing of CLI input for a while.",
                  "waitTimeUs" SL_CLI_UNIT_SEPARATOR "['rel'=Relative] 'abs'=Absolute" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_STRINGOPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__clearScript = \
  SL_CLI_COMMAND(clearScript,
                 "Clear the script entered via enterScript.",
                  "[0=RAM] 1=Flash" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__printScript = \
  SL_CLI_COMMAND(printScript,
                 "Print the script entered via enterScript.",
                  "[0=RAM] 1=Flash" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__enterScript = \
  SL_CLI_COMMAND(enterScript,
                 "Enter script entry mode.\n                    Conclude entry mode with text 'endScript'.",
                  "[0=RAM] 1=Flash-script will run on boot" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__runScript = \
  SL_CLI_COMMAND(runScript,
                 "Run the script entered via enterScript.",
                  "[0=RAM] 1=Flash-script will run on boot" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__setRetimeOption = \
  SL_CLI_COMMAND(setRetimeOption,
                 "Control retime options.",
                  "optionBitMask: 1=HFXO | 2=HFRCO | 4=DCDC | 8=LCD" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__set_tx_antenna_mode = \
  SL_CLI_COMMAND(cli_ant_div_set_tx_antenna_mode,
                 "set the tx antenna mode",
                  "0=Disable 1=ANTENNA1 2=ANTENNA2 3=DIVERSITY" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__get_tx_antenna_mode = \
  SL_CLI_COMMAND(cli_ant_div_get_tx_antenna_mode,
                 "get the tx antenna mode 0=Disable 1=ANTENNA1 2=ANTENNA2 3=DIVERSITY",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__get_tx_antenna_selected = \
  SL_CLI_COMMAND(cli_ant_div_get_tx_antenna_selected,
                 "get the currently selected tx antenna 1=ANTENNA1 2=ANTENNA2",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__toggle_tx_antenna = \
  SL_CLI_COMMAND(cli_ant_div_toggle_tx_antenna,
                 "toggle the tx antenna selection",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__set_rx_antenna_mode = \
  SL_CLI_COMMAND(cli_ant_div_set_rx_antenna_mode,
                 "set the rx antenna mode",
                  "0=Disable 1=ANTENNA1 2=ANTENNA2 3=DIVERSITY" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__get_rx_antenna_mode = \
  SL_CLI_COMMAND(cli_ant_div_get_rx_antenna_mode,
                 "get the rx antenna mode 0=Disable 1=ANTENNA1 2=ANTENNA2 3=DIVERSITY",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__get_ant_div_phy_select = \
  SL_CLI_COMMAND(cli_ant_div_get_phy_select,
                 "get the antenna diversity phy selection",
                  "",
                 {SL_CLI_ARG_END, });
#endif

// Create group command tables and structs if cli_groups given
// in template. Group name is suffixed with _group_table for tables
// and group commands are cli_cmd_grp_( group name )
// Create root command table
const sl_cli_command_entry_t sl_cli_default_command_table[] = {
  { "_________________________________", &cli_cmd___________________________________, false },
  { "____Application_Configuration____", &cli_cmd______Application_Configuration____, false },
#ifndef RAIL_LIGHTWEIGHT
  { "setEventConfig", &cli_cmd__setEventConfig, false },
#endif
  { "resetCounters", &cli_cmd__resetCounters, false },
#ifndef RAIL_LIGHTWEIGHT
  { "setPeripheralEnable", &cli_cmd__setPeripheralEnable, false },
  { "setNotifications", &cli_cmd__setNotifications, false },
  { "getLogLevels", &cli_cmd__getLogLevels, false },
#endif
  { "getVersion", &cli_cmd__getVersion, false },
#ifndef RAIL_LIGHTWEIGHT
  { "getVersionVerbose", &cli_cmd__getVersionVerbose, false },
  { "setPtiProtocol", &cli_cmd__setPtiProtocol, false },
  { "getPti", &cli_cmd__getPti, false },
  { "setPrintingEnable", &cli_cmd__setPrintingEnable, false },
#endif
  { "____________________________", &cli_cmd______________________________, false },
  { "____Receive_and_Transmit____", &cli_cmd______Receive_and_Transmit____, false },
  { "rx", &cli_cmd__rx, false },
#ifndef RAIL_LIGHTWEIGHT
  { "r", &cli_cmd__rx, true },
  { "rxAt", &cli_cmd__rxAt, false },
#endif
  { "setRxOptions", &cli_cmd__setRxOptions, false },
  { "configRxOptions", &cli_cmd__setRxOptions, true },
  { "tx", &cli_cmd__tx, false },
#ifndef RAIL_LIGHTWEIGHT
  { "t", &cli_cmd__tx, true },
  { "txWithOptions", &cli_cmd__txWithOptions, false },
  { "txAfterRx", &cli_cmd__txAfterRx, false },
#endif
  { "configTxOptions", &cli_cmd__configTxOptions, false },
  { "setTxOptions", &cli_cmd__configTxOptions, true },
  { "setFixedLength", &cli_cmd__setFixedLength, false },
  { "setPower", &cli_cmd__setPower, false },
  { "getPower", &cli_cmd__getPower, false },
#ifndef RAIL_LIGHTWEIGHT
  { "setPowerConfig", &cli_cmd__setPowerConfig, false },
  { "getPowerConfig", &cli_cmd__getPowerConfig, false },
  { "getPowerLimits", &cli_cmd__getPowerLimits, false },
  { "enablePaAutoMode", &cli_cmd__enablePaAutoMode, false },
  { "configPaAutoMode", &cli_cmd__configPaAutoMode, false },
  { "sweepTxPower", &cli_cmd__sweepTxPower, false },
  { "offsetLqi", &cli_cmd__offsetLqi, false },
#endif
  { "getRssi", &cli_cmd__getRssi, false },
#ifndef RAIL_LIGHTWEIGHT
  { "sweepPower", &cli_cmd__sweepPower, false },
  { "startAvgRssi", &cli_cmd__startAvgRssi, false },
  { "getAvgRssi", &cli_cmd__getAvgRssi, false },
#endif
  { "setTxTone", &cli_cmd__setTxTone, false },
  { "setTxStream", &cli_cmd__setTxStream, false },
  { "status", &cli_cmd__status, false },
#ifndef RAIL_LIGHTWEIGHT
  { "fifoStatus", &cli_cmd__fifoStatus, false },
  { "setTxHoldOff", &cli_cmd__setTxHoldOff, false },
#endif
  { "setTxDelay", &cli_cmd__setTxDelay, false },
  { "getTxDelay", &cli_cmd__getTxDelay, false },
  { "setTxPayload", &cli_cmd__setTxPayload, false },
  { "setTxPayloadQuiet", &cli_cmd__setTxPayloadQuiet, false },
  { "setTxLength", &cli_cmd__setTxLength, false },
  { "printTxPacket", &cli_cmd__printTxPacket, false },
#ifndef RAIL_LIGHTWEIGHT
  { "peek", &cli_cmd__peek, false },
  { "getTime", &cli_cmd__getTime, false },
  { "setTime", &cli_cmd__setTime, false },
  { "dataConfig", &cli_cmd__dataConfig, false },
  { "setRxFifo", &cli_cmd__setRxFifo, false },
  { "setTxFifoThreshold", &cli_cmd__setTxFifoThreshold, false },
  { "setRxFifoThreshold", &cli_cmd__setRxFifoThreshold, false },
  { "fifoModeTestOptions", &cli_cmd__fifoModeTestOptions, false },
  { "rxFifoManualRead", &cli_cmd__rxFifoManualRead, false },
  { "txFifoManualLoad", &cli_cmd__txFifoManualLoad, false },
  { "fifoReset", &cli_cmd__fifoReset, false },
  { "abortRxPacket", &cli_cmd__abortRxPacket, false },
  { "printTxAcks", &cli_cmd__printTxAcks, false },
  { "configRxHopping", &cli_cmd__configRxHopping, false },
  { "configRxChannelHopping", &cli_cmd__configRxHopping, true },
  { "enableRxHopping", &cli_cmd__enableRxHopping, false },
  { "enableRxChannelHopping", &cli_cmd__enableRxHopping, true },
  { "configRxHoppingOpts", &cli_cmd__configRxHoppingOpts, false },
  { "configChannelHoppingOptions", &cli_cmd__configRxHoppingOpts, true },
  { "configRxMultiHop", &cli_cmd__configRxMultiHop, false },
  { "configChannelHoppingMulti", &cli_cmd__configRxMultiHop, true },
  { "getRxHoppingRssi", &cli_cmd__getRxHoppingRssi, false },
  { "getChannelHoppingRssi", &cli_cmd__getRxHoppingRssi, true },
  { "spectrumAnalyzer", &cli_cmd__spectrumAnalyzer, false },
  { "configRxDutyCycle", &cli_cmd__configRxDutyCycle, false },
  { "enableRxDutyCycle", &cli_cmd__enableRxDutyCycle, false },
  { "setTxAltPreambleLen", &cli_cmd__setTxAltPreambleLen, false },
  { "configSyncWords", &cli_cmd__configSyncWords, false },
  { "getSyncWords", &cli_cmd__getSyncWords, false },
  { "printRxErrors", &cli_cmd__printRxErrors, false },
  { "printRxFreqOffsets", &cli_cmd__printRxFreqOffsets, false },
  { "printDataRates", &cli_cmd__printDataRates, false },
  { "stopInfinitePream", &cli_cmd__stopInfinitePream, false },
  { "stopInfinitePreambleTx", &cli_cmd__stopInfinitePream, true },
  { "___________________________________", &cli_cmd_____________________________________, false },
  { "____Energy_Modes_and_RF_Sensing____", &cli_cmd______Energy_Modes_and_RF_Sensing____, false },
  { "sleep", &cli_cmd__sleep, false },
  { "rfsense", &cli_cmd__rfsense, false },
  { "configRfSenseWakeup", &cli_cmd__configRfSenseWakeup, false },
  { "configRfSenseWakeupPhy", &cli_cmd__configRfSenseWakeup, true },
  { "setRfSenseTxPayload", &cli_cmd__setRfSenseTxPayload, false },
  { "_________________________", &cli_cmd___________________________, false },
  { "____Address_Filtering____", &cli_cmd______Address_Filtering____, false },
  { "configAddressFilter", &cli_cmd__configAddressFilter, false },
  { "setAddressFiltering", &cli_cmd__setAddressFiltering, false },
  { "getAddressFiltering", &cli_cmd__getAddressFiltering, false },
  { "printAddresses", &cli_cmd__printAddresses, false },
  { "setAddress", &cli_cmd__setAddress, false },
  { "setAddressMask", &cli_cmd__setAddressMask, false },
  { "setAddressEnable", &cli_cmd__setAddressEnable, false },
#endif
  { "__________________________", &cli_cmd____________________________, false },
  { "____Error_Rate_Testing____", &cli_cmd______Error_Rate_Testing____, false },
  { "perRx", &cli_cmd__perRx, false },
  { "perStatus", &cli_cmd__perStatus, false },
  { "setBerConfig", &cli_cmd__setBerConfig, false },
  { "berRx", &cli_cmd__berRx, false },
  { "berStatus", &cli_cmd__berStatus, false },
#ifndef RAIL_LIGHTWEIGHT
  { "______________________________", &cli_cmd________________________________, false },
  { "____Listen_Before_Talk_LBT____", &cli_cmd______Listen_Before_Talk_LBT____, false },
  { "setLbtMode", &cli_cmd__setLbtMode, false },
  { "getLbtParams", &cli_cmd__getLbtParams, false },
  { "setLbtParams", &cli_cmd__setLbtParams, false },
  { "_____________________", &cli_cmd_______________________, false },
  { "____802_15_4_Mode____", &cli_cmd______802_15_4_Mode____, false },
  { "enable802154", &cli_cmd__enable802154, false },
  { "config2p4GHz802154", &cli_cmd__config2p4GHz802154, false },
  { "config863MHz802154", &cli_cmd__config863MHz802154, false },
  { "config915MHz802154", &cli_cmd__config915MHz802154, false },
  { "set802154e", &cli_cmd__set802154e, false },
  { "set802154g", &cli_cmd__set802154g, false },
  { "set802154FpMode", &cli_cmd__set802154FpMode, false },
  { "acceptFrames", &cli_cmd__acceptFrames, false },
  { "setPromiscuousMode", &cli_cmd__setPromiscuousMode, false },
  { "setPanCoordinator", &cli_cmd__setPanCoordinator, false },
  { "setPanId802154", &cli_cmd__setPanId802154, false },
  { "setShortAddr802154", &cli_cmd__setShortAddr802154, false },
  { "setLongAddr802154", &cli_cmd__setLongAddr802154, false },
  { "setAddresses802154", &cli_cmd__setAddresses802154, false },
  { "setDataReqLatency", &cli_cmd__setDataReqLatency, false },
  { "________________", &cli_cmd__________________, false },
  { "____BLE_Mode____", &cli_cmd______BLE_Mode____, false },
  { "setBleMode", &cli_cmd__setBleMode, false },
  { "getBleMode", &cli_cmd__getBleMode, false },
  { "setBleChannelParams", &cli_cmd__setBleChannelParams, false },
  { "setBlePhySwitchToRx", &cli_cmd__setBlePhySwitchToRx, false },
  { "setBleAdvertising", &cli_cmd__setBleAdvertising, false },
  { "setBle1Mbps", &cli_cmd__setBle1Mbps, false },
  { "setBle2Mbps", &cli_cmd__setBle2Mbps, false },
  { "setBleCoding", &cli_cmd__setBleCoding, false },
  { "setBleSimulscan", &cli_cmd__setBleSimulscan, false },
  { "___________________", &cli_cmd_____________________, false },
  { "____Z_Wave_Mode____", &cli_cmd______Z_Wave_Mode____, false },
  { "setZWaveMode", &cli_cmd__setZWaveMode, false },
  { "getZWaveMode", &cli_cmd__getZWaveMode, false },
  { "setZWaveRegion", &cli_cmd__setZWaveRegion, false },
  { "getZWaveRegion", &cli_cmd__getZWaveRegion, false },
  { "listZWaveRegions", &cli_cmd__listZWaveRegions, false },
  { "getZWaveBaudRate", &cli_cmd__getZWaveBaudRate, false },
  { "setZWaveNodeId", &cli_cmd__setZWaveNodeId, false },
  { "setZWaveHomeId", &cli_cmd__setZWaveHomeId, false },
  { "setZWaveOptions", &cli_cmd__setZWaveOptions, false },
  { "setZWaveLowPower", &cli_cmd__setZWaveLowPower, false },
  { "getZWaveLowPower", &cli_cmd__getZWaveLowPower, false },
  { "zwaveReceiveBeam", &cli_cmd__zwaveReceiveBeam, false },
  { "setMfmMode", &cli_cmd__setMfmMode, false },
  { "getMfmMode", &cli_cmd__getMfmMode, false },
  { "__________________", &cli_cmd____________________, false },
  { "____RAIL_Timer____", &cli_cmd______RAIL_Timer____, false },
  { "setTimer", &cli_cmd__setTimer, false },
  { "timerCancel", &cli_cmd__timerCancel, false },
  { "printTimerStats", &cli_cmd__printTimerStats, false },
  { "enableMultiTimer", &cli_cmd__enableMultiTimer, false },
  { "setMultiTimer", &cli_cmd__setMultiTimer, false },
  { "multiTimerCancel", &cli_cmd__multiTimerCancel, false },
  { "getMultiTimerStats", &cli_cmd__getMultiTimerStats, false },
  { "printMultiTimerStats", &cli_cmd__getMultiTimerStats, true },
  { "delayUs", &cli_cmd__delayUs, false },
  { "____________________", &cli_cmd______________________, false },
  { "____Auto_ACK_ing____", &cli_cmd______Auto_ACK_ing____, false },
  { "autoAckConfig", &cli_cmd__autoAckConfig, false },
  { "autoAckDisable", &cli_cmd__autoAckDisable, false },
  { "setAckPayload", &cli_cmd__setAckPayload, false },
  { "setAckLength", &cli_cmd__setAckLength, false },
  { "printAckPacket", &cli_cmd__printAckPacket, false },
  { "getAutoAck", &cli_cmd__getAutoAck, false },
  { "autoAckPause", &cli_cmd__autoAckPause, false },
  { "setTxAckOptions", &cli_cmd__setTxAckOptions, false },
  { "______________________", &cli_cmd________________________, false },
  { "____GPIO_Functions____", &cli_cmd______GPIO_Functions____, false },
  { "setGpioOutPin", &cli_cmd__setGpioOutPin, false },
#endif
  { "___________________________", &cli_cmd_____________________________, false },
  { "____Diagnostic_and_Test____", &cli_cmd______Diagnostic_and_Test____, false },
#ifndef RAIL_LIGHTWEIGHT
  { "getConfigIndex", &cli_cmd__getConfigIndex, false },
  { "setConfigIndex", &cli_cmd__setConfigIndex, false },
#endif
  { "setCtune", &cli_cmd__setCtune, false },
  { "getCtune", &cli_cmd__getCtune, false },
#ifndef RAIL_LIGHTWEIGHT
  { "setCtuneDelta", &cli_cmd__setCtuneDelta, false },
  { "getCtuneDelta", &cli_cmd__getCtuneDelta, false },
  { "setPaCtune", &cli_cmd__setPaCtune, false },
  { "enablePaCal", &cli_cmd__enablePaCal, false },
  { "setDebugSignal", &cli_cmd__setDebugSignal, false },
  { "setDebugMode", &cli_cmd__setDebugMode, false },
  { "freqOverride", &cli_cmd__freqOverride, false },
  { "directMode", &cli_cmd__directMode, false },
  { "directTx", &cli_cmd__directTx, false },
  { "txCancel", &cli_cmd__txCancel, false },
  { "startThermistor", &cli_cmd__startThermistor, false },
  { "startThermistorMeasurement", &cli_cmd__startThermistor, true },
  { "getThermistor", &cli_cmd__getThermistor, false },
  { "getThermistorImpedance", &cli_cmd__getThermistor, true },
  { "getRandom", &cli_cmd__getRandom, false },
  { "setTxUnderflow", &cli_cmd__setTxUnderflow, false },
  { "setRxOverflow", &cli_cmd__setRxOverflow, false },
  { "setCalibrations", &cli_cmd__setCalibrations, false },
  { "setTxTransitions", &cli_cmd__setTxTransitions, false },
  { "setRxTransitions", &cli_cmd__setRxTransitions, false },
  { "getTxTransitions", &cli_cmd__getTxTransitions, false },
  { "getRxTransitions", &cli_cmd__getRxTransitions, false },
  { "setNextTxRepeat", &cli_cmd__setNextTxRepeat, false },
  { "setNextBleTxRepeat", &cli_cmd__setNextBleTxRepeat, false },
  { "setTxTimePos", &cli_cmd__setTxTimePos, false },
  { "setRxTimePos", &cli_cmd__setRxTimePos, false },
  { "setTimings", &cli_cmd__setTimings, false },
  { "forceAssert", &cli_cmd__forceAssert, false },
  { "getAppMode", &cli_cmd__getAppMode, false },

  { "getRadioState", &cli_cmd__getRadioState, false },
  { "verifyRadio", &cli_cmd__verifyRadio, false },
#endif
  { "getChannel", &cli_cmd__getChannel, false },
  { "setChannel", &cli_cmd__setChannel, false },
  { "reset", &cli_cmd__reset, false },
#ifndef RAIL_LIGHTWEIGHT
  { "writeRmrStructure", &cli_cmd__writeRmrStructure, false },
  { "updateConfigPtr", &cli_cmd__updateConfigPtr, false },
  { "updateConfigurationPointer", &cli_cmd__updateConfigPtr, true },
  { "reconfigureModem", &cli_cmd__reconfigureModem, false },
  { "printEvents", &cli_cmd__printEvents, false },
  { "printChipFeatures", &cli_cmd__printChipFeatures, false },
#endif
  { "getmemw", &cli_cmd__getmemw, false },
  { "setmemw", &cli_cmd__setmemw, false },
#ifndef RAIL_LIGHTWEIGHT
  { "throughput", &cli_cmd__throughput, false },
  { "setRssiOffset", &cli_cmd__setRssiOffset, false },
  { "getRssiOffset", &cli_cmd__getRssiOffset, false },
  { "txAt", &cli_cmd__txAt, false },
  { "setFreqOffset", &cli_cmd__setFreqOffset, false },
  { "holdRx", &cli_cmd__holdRx, false },
  { "wait", &cli_cmd__wait, false },
  { "clearScript", &cli_cmd__clearScript, false },
  { "printScript", &cli_cmd__printScript, false },
  { "enterScript", &cli_cmd__enterScript, false },
  { "runScript", &cli_cmd__runScript, false },
  { "setRetimeOption", &cli_cmd__setRetimeOption, false },
  { "set_tx_antenna_mode", &cli_cmd__set_tx_antenna_mode, false },
  { "get_tx_antenna_mode", &cli_cmd__get_tx_antenna_mode, false },
  { "get_tx_antenna_selected", &cli_cmd__get_tx_antenna_selected, false },
  { "toggle_tx_antenna", &cli_cmd__toggle_tx_antenna, false },
  { "set_rx_antenna_mode", &cli_cmd__set_rx_antenna_mode, false },
  { "get_rx_antenna_mode", &cli_cmd__get_rx_antenna_mode, false },
  { "get_ant_div_phy_select", &cli_cmd__get_ant_div_phy_select, false },
#endif
  { NULL, NULL, false },
};


#ifdef __cplusplus
}
#endif
