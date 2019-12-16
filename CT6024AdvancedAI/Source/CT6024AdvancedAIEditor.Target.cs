// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class CT6024AdvancedAIEditorTarget : TargetRules
{
	public CT6024AdvancedAIEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "CT6024AdvancedAI" } );
	}
}
