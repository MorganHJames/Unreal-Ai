// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class CT6024AdvancedAITarget : TargetRules
{
	public CT6024AdvancedAITarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "CT6024AdvancedAI" } );
	}
}
