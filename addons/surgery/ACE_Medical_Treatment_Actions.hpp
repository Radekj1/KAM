class ACE_Medical_Treatment_Actions {
    class BasicBandage;
    class FieldDressing;
    class ApplyTourniquet;
    class RemoveTourniquet;
    class Morphine;
    class CheckPulse;
    class CPR;
    class Carbonate;
    class Defibrillator_AED_X_vehicle;

    class CheckFracture: CheckPulse {
        displayName = CSTRING(fracture_check);
        displayNameProgress = CSTRING(fracture_checking);
        category = "examine";
        treatmentLocations = 0;
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = QGVAR(enable_selfCheckFracture);
        medicRequired = QGVAR(fractureCheck_MedLevel);
        treatmentTime = QGVAR(fractureCheck_Time);
        items[] = {};
        condition = QUOTE(([ARR_4(_medic, _patient, _bodyPart, 5)] call FUNC(fractureCheck)) && (GVAR(enable_fracture)));
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_3(_medic, _patient, _bodyPart)] call FUNC(fractureSelect));
    };
    class ClosedReduction: CheckFracture {
        displayName = CSTRING(fracture_closed);
        displayNameProgress = CSTRING(perform);
        category = "surgery";
        treatmentLocations = QGVAR(closedLocation);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(closedReduction_MedLevel);
        treatmentTime = QGVAR(closedTime);
        items[] = {};
        condition = "true";
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_3(_medic, _patient, _bodyPart)] call FUNC(closedFracture));
    };
    class OpenReduction: CheckFracture {
        displayName = CSTRING(fracture_open);
        displayNameProgress = CSTRING(perform);
        category = "surgery";
        treatmentLocations = QGVAR(surgicalLocation);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(surgicalAction_MedLevel);
        treatmentTime = QGVAR(openTime);
        items[] = {};
        condition = "true";
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_3(_medic, _patient, _bodyPart)] call FUNC(openFracture));
    };
    class Etomidate: Carbonate {
        displayName = CSTRING(Etomidate_Use);
        category = "surgery";
        treatmentLocations = 0;
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(Etomidate_MedLevel);
        treatmentTime = QEGVAR(pharma,PushTime);
        items[] = {"kat_etomidate"};
        condition = QEFUNC(pharma,removeIV);
        patientStateCondition = 0;
        callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_medication;";
    };
    class Lorazepam: Carbonate {
        displayName = CSTRING(Lorazepam_Use);
        category = "surgery";
        treatmentLocations = 0;
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(Lorazepam_MedLevel);
        treatmentTime = QEGVAR(pharma,PushTime);
        items[] = {"kat_lorazepam"};
        condition = QEFUNC(pharma,removeIV);
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_3(_player, _patient, 'Lorazepam')] call FUNC(treatmentAdvanced_Generic));
    };
    class Flumazenil: Carbonate {
        displayName = CSTRING(Flumazenil_Use);
        category = "surgery";
        treatmentLocations = 0;
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(Flumazenil_MedLevel);
        treatmentTime = QEGVAR(pharma,PushTime);
        items[] = {"kat_flumazenil"};
        condition = QEFUNC(pharma,removeIV);
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_3(_player, _patient, 'Flumazenil')] call FUNC(treatmentAdvanced_Generic));
    };
    class Expose: BasicBandage {
        displayName = CSTRING(Retractor_Use);
        displayNameProgress = CSTRING(Retractor_Action);
        category = "surgery";
        treatmentLocations = QGVAR(surgicalLocation);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(surgicalAction_MedLevel);
        treatmentTime = QGVAR(intermediateTime);
        items[] = {"kat_retractor"};
        condition = "true";
        consumeItem = 0;
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_4(_medic, _patient, _bodyPart, 2.1)] call FUNC(openFractureProgress));
    };
    class Incision: BasicBandage {
        displayName = CSTRING(Scalpel_Use);
        displayNameProgress = CSTRING(perform);
        category = "surgery";
        treatmentLocations = QGVAR(surgicalLocation);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(surgicalAction_MedLevel);
        treatmentTime = QGVAR(incisionTime);
        items[] = {"kat_scalpel"};
        condition = "true";
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_3(_medic, _patient, _bodyPart)] call FUNC(openFractureIncision));
    };
    class Clamp: BasicBandage {
        displayName = CSTRING(Clamp_Use);
        displayNameProgress = CSTRING(Clamp_Action);
        category = "surgery";
        treatmentLocations = QGVAR(surgicalLocation);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(surgicalAction_MedLevel);
        treatmentTime = QGVAR(intermediateTime);
        items[] = {"kat_clamp"};
        condition = "true";
        consumeItem = 0;
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_4(_medic, _patient, _bodyPart, 3.3)] call FUNC(openFractureProgress));
    };
    class Irrigate: BasicBandage {
        displayName = CSTRING(Irrigate_Use);
        displayNameProgress = CSTRING(Irrigate_Action);
        category = "surgery";
        treatmentLocations = QGVAR(surgicalLocation);
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(surgicalAction_MedLevel);
        treatmentTime = QGVAR(intermediateTime);
        items[] = {"ACE_salineIV_250"};
        condition = "true";
        patientStateCondition = 0;
        callbackSuccess = QUOTE([ARR_4(_medic, _patient, _bodyPart, 2.3)] call FUNC(openFractureProgress));
    };
    class Debridement: BasicBandage {
        displayName = CSTRING(Debride_Use);
        displayNameProgress = CSTRING(Debride_Action);
        category = "surgery";
        treatmentLocations = QGVAR(surgicalLocation);
        allowedSelections[] = {"Head", "Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(surgicalAction_MedLevel);
        treatmentTime = QGVAR(debrideTime);
        items[] = {"kat_scalpel"};
        condition = "true";
        consumeItem = 0;
        callbackSuccess = QUOTE([ARR_3(_medic, _patient, _bodyPart)] call FUNC(debridementClear));
    };
    class NPWT: BasicBandage {
        displayName = CSTRING(Vacuum_Use);
        displayNameProgress = CSTRING(Vacuum_Action);
        category = "surgery";
        treatmentLocations = QGVAR(surgicalLocation);
        allowedSelections[] = {"Head", "Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(surgicalAction_MedLevel);
        treatmentTime = QGVAR(npwtTime);
        items[] = {"kat_vacuum"};
        condition = "true";
        consumeItem = 0;
        callbackStart = QUOTE([ARR_2(_medic, _patient)] call FUNC(debridementStart));
        callbackSuccess = QUOTE([ARR_3(_medic, _patient, _bodyPart)] call FUNC(debridementMinor));
    };
};
