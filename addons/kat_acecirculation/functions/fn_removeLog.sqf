/*
 * Author: Katalam
 * Remove a given log from the ace medical menu.
 *
 * Arguments:
 * 0: Target <OBJECT>
 * 1: Type <STRING>
 * 2: Message <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorTarget, "quick_view", "STR_kat_aceBreathing_pulseoxi_Log"] call kat_aceCirculation_fnc_removeLog;
 *
 * Public: No
 */

params ["_target", "_type", "_message"];

private _logVarName = format ["ace_medical_logFile_%1", _type];

private _logs = _target getVariable ["ace_medical_allLogs", []];
if !(_logVarName in _logs) exitWith {false};

private _log = _target getVariable [_logVarName, []];

private _newLog = [];

{
	if !(_x select 0 isEqualTo _message) then {
        _newLog pushBack _x;
    };
} forEach _log;
_log = _newLog;

_target setVariable [_logVarName, _log, true];
