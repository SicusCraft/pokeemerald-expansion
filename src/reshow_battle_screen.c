#include "global.h"
#include "reshow_battle_screen.h"
#include "battle.h"
#include "palette.h"
#include "pokemon.h"
#include "main.h"
#include "scanline_effect.h"
#include "text.h"
#include "gpu_regs.h"
#include "bg.h"
#include "battle_controllers.h"
#include "link.h"
#include "sprite.h"
#include "constants/trainers.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "data.h"

// this file's functions
static void CB2_ReshowBattleScreenAfterMenu(void);
static void CB2_ReshowBlankBattleScreenAfterMenu(void);
static bool8 LoadBattlerSpriteGfx(u32 battler);
static void CreateHealthboxSprite(u32 battler);
static void ClearBattleBgCntBaseBlocks(void);
static void CreateCaughtMonSprite(void);

void ReshowBattleScreenDummy(void)
{

}

void ReshowBattleScreenAfterMenu(void)
{
    gPaletteFade.bufferTransferDisabled = 1;
    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    gBattleScripting.reshowMainState = 0;
    gBattleScripting.reshowHelperState = 0;
    SetMainCallback2(CB2_ReshowBattleScreenAfterMenu);
}

static void CB2_ReshowBattleScreenAfterMenu(void)
{
    switch (gBattleScripting.reshowMainState)
    {
    case 0:
        ScanlineEffect_Clear();
        BattleInitBgsAndWindows();
        SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 0);
        SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 0);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        ResetPaletteFade();
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        gBattle_BG2_X = 0;
        gBattle_BG2_Y = 0;
        gBattle_BG3_X = 0;
        gBattle_BG3_Y = 0;
        break;
    case 1:
        CpuFastFill(0, (void *)(VRAM), VRAM_SIZE);
        break;
    case 2:
        LoadBattleTextboxAndBackground();
        break;
    case 3:
        ResetSpriteData();
        break;
    case 4:
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = MAX_BATTLERS_COUNT;
        break;
    case 5:
        ClearSpritesHealthboxAnimData();
        break;
    case 6:
        if (BattleLoadAllHealthBoxesGfx(gBattleScripting.reshowHelperState))
        {
            gBattleScripting.reshowHelperState = 0;
        }
        else
        {
            gBattleScripting.reshowHelperState++;
            gBattleScripting.reshowMainState--;
        }
        break;
    case 7:
        if (!LoadBattlerSpriteGfx(0))
            gBattleScripting.reshowMainState--;
        break;
    case 8:
        if (!LoadBattlerSpriteGfx(1))
            gBattleScripting.reshowMainState--;
        break;
    case 9:
        if (!LoadBattlerSpriteGfx(2))
            gBattleScripting.reshowMainState--;
        break;
    case 10:
        if (!LoadBattlerSpriteGfx(3))
            gBattleScripting.reshowMainState--;
        break;
    case 11:
        CreateBattlerSprite(0);
        break;
    case 12:
        CreateBattlerSprite(1);
        break;
    case 13:
        CreateBattlerSprite(2);
        break;
    case 14:
        CreateBattlerSprite(3);
        break;
    case 15:
        CreateHealthboxSprite(0);
        break;
    case 16:
        CreateHealthboxSprite(1);
        break;
    case 17:
        CreateHealthboxSprite(2);
        break;
    case 18:
        CreateHealthboxSprite(3);
        break;
    case 19:
        {
            u8 opponentBattler;
            u16 species;

            LoadAndCreateEnemyShadowSprites();

            opponentBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            species = GetMonData(GetBattlerMon(opponentBattler), MON_DATA_SPECIES);
            SetBattlerShadowSpriteCallback(opponentBattler, species);

            if (IsDoubleBattle())
            {
                opponentBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
                species = GetMonData(GetBattlerMon(opponentBattler), MON_DATA_SPECIES);
                SetBattlerShadowSpriteCallback(opponentBattler, species);
            }

            ActionSelectionCreateCursorAt(gActionSelectionCursor[gBattlerInMenuId], 0);

            if (gWirelessCommType != 0 && gReceivedRemoteLinkPlayers)
            {
                LoadWirelessStatusIndicatorSpriteGfx();
                CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        break;
    default:
        SetVBlankCallback(VBlankCB_Battle);
        ClearBattleBgCntBaseBlocks();
        BeginHardwarePaletteFade(0xFF, 0, 0x10, 0, 1);
        gPaletteFade.bufferTransferDisabled = 0;
        SetMainCallback2(BattleMainCB2);
        FillAroundBattleWindows();
        break;
    }

    gBattleScripting.reshowMainState++;
}

void ReshowBlankBattleScreenAfterMenu(void)
{
    gPaletteFade.bufferTransferDisabled = 1;
    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    gBattleScripting.reshowMainState = 0;
    gBattleScripting.reshowHelperState = 0;
    SetMainCallback2(CB2_ReshowBlankBattleScreenAfterMenu);
}

static void CB2_ReshowBlankBattleScreenAfterMenu(void)
{
    switch (gBattleScripting.reshowMainState)
    {
    case 0:
        ScanlineEffect_Clear();
        BattleInitBgsAndWindows();
        SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 0);
        SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 0);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        ResetPaletteFade();
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        gBattle_BG2_X = 0;
        gBattle_BG2_Y = 0;
        gBattle_BG3_X = 255;
        gBattle_BG3_Y = 0;
        break;
    case 1:
        CpuFastFill(0, (void *)(VRAM), VRAM_SIZE);
        break;
    case 2:
        LoadBattleTextboxAndBackground();
        break;
    case 3:
        ResetSpriteData();
        break;
    case 4:
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = MAX_BATTLERS_COUNT;
        break;
    case 5:
        ClearSpritesHealthboxAnimData();
        break;
    case 6:
        if (!LoadBattlerSpriteGfx(0))
            gBattleScripting.reshowMainState--;
        break;
    case 7:
        if (!LoadBattlerSpriteGfx(1))
            gBattleScripting.reshowMainState--;
        break;
    case 8:
        if (!LoadBattlerSpriteGfx(2))
            gBattleScripting.reshowMainState--;
        break;
    case 9:
        if (!LoadBattlerSpriteGfx(3))
            gBattleScripting.reshowMainState--;
        break;
    case 10:
        if (gBattleScripting.monCaught) 
            CreateCaughtMonSprite(); // displays the caught mon for the switch into party feature
        break;
    default:
        SetVBlankCallback(VBlankCB_Battle);
        ClearBattleBgCntBaseBlocks();
        BeginHardwarePaletteFade(0xFF, 0, 0x10, 0, 1);
        gPaletteFade.bufferTransferDisabled = 0;
        SetMainCallback2(BattleMainCB2);
        FillAroundBattleWindows();
        break;
    }

    gBattleScripting.reshowMainState++;
}

static void ClearBattleBgCntBaseBlocks(void)
{
    vBgCnt *regBgcnt1, *regBgcnt2;

    regBgcnt1 = (vBgCnt *)(&REG_BG1CNT);
    regBgcnt1->charBaseBlock = 0;

    regBgcnt2 = (vBgCnt *)(&REG_BG2CNT);
    regBgcnt2->charBaseBlock = 0;
}

static bool8 LoadBattlerSpriteGfx(u32 battler)
{
    if (battler < gBattlersCount)
    {
        if (!IsOnPlayerSide(battler))
        {
            if (!gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
                BattleLoadMonSpriteGfx(GetBattlerMon(battler), battler);
            else
                BattleLoadSubstituteOrMonSpriteGfx(battler, FALSE);
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && battler == B_POSITION_PLAYER_LEFT) // Should be checking position, not battler.
            DecompressTrainerBackPic(gSaveBlock2Ptr->playerGender, battler);
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && battler == B_POSITION_PLAYER_LEFT) // Should be checking position, not battler.
            DecompressTrainerBackPic(TRAINER_BACK_PIC_OAK, battler);
        else if (!gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            BattleLoadMonSpriteGfx(GetBattlerMon(battler), battler);
        else
            BattleLoadSubstituteOrMonSpriteGfx(battler, FALSE);

        gBattleScripting.reshowHelperState = 0;
    }
    return TRUE;
}

void CreateBattlerSprite(u32 battler)
{
    if (battler < gBattlersCount)
    {
        u8 posY;

        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            posY = GetSubstituteSpriteDefault_Y(battler);
        else
            posY = GetBattlerSpriteDefault_Y(battler);

        if (!IsOnPlayerSide(battler))
        {
            if (GetMonData(GetBattlerMon(battler), MON_DATA_HP) == 0)
                return;
            if (gBattleScripting.monCaught) // Don't create opponent sprite if it has been caught.
                return;

            SetMultiuseSpriteTemplateToPokemon(GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES), GetBattlerPosition(battler));
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2), posY, GetBattlerSpriteSubpriority(battler));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
            gSprites[gBattlerSpriteIds[battler]].data[2] = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);

            StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && battler == B_POSITION_PLAYER_LEFT)
        {
            SetMultiuseSpriteTemplateToTrainerBack(gSaveBlock2Ptr->playerGender, GetBattlerPosition(B_POSITION_PLAYER_LEFT));
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, 0x50,
                                                (8 - gTrainerBacksprites[gSaveBlock2Ptr->playerGender].coordinates.size) * 4 + 80,
                                                 GetBattlerSpriteSubpriority(0));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && battler == B_POSITION_PLAYER_LEFT)
        {
            SetMultiuseSpriteTemplateToTrainerBack(TRAINER_BACK_PIC_OAK, GetBattlerPosition(0));
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, 0x50,
                                                (8 - gTrainerBacksprites[TRAINER_BACK_PIC_OAK].coordinates.size) * 4 + 80,
                                                 GetBattlerSpriteSubpriority(0));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
        }
        else
        {
            if (!IsValidForBattle(GetBattlerMon(battler)))
                return;

            SetMultiuseSpriteTemplateToPokemon(GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES), GetBattlerPosition(battler));
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2), posY, GetBattlerSpriteSubpriority(battler));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
            gSprites[gBattlerSpriteIds[battler]].data[2] = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);

            StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
        }

        gSprites[gBattlerSpriteIds[battler]].invisible = gBattleSpritesDataPtr->battlerData[battler].invisible;
    }
}

static void CreateHealthboxSprite(u32 battler)
{
    if (battler < gBattlersCount)
    {
        u8 healthboxSpriteId;

        if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && battler == B_POSITION_PLAYER_LEFT)
            healthboxSpriteId = CreateSafariPlayerHealthboxSprites();
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && battler == B_POSITION_PLAYER_LEFT)
            return;
        else
            healthboxSpriteId = CreateBattlerHealthboxSprites(battler);

        gHealthboxSpriteIds[battler] = healthboxSpriteId;
        InitBattlerHealthboxCoords(battler);
        SetHealthboxSpriteVisible(healthboxSpriteId);

        if (!IsOnPlayerSide(battler))
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_SAFARI_ALL_TEXT);
        else
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);

        if (GetBattlerPosition(battler) == B_POSITION_OPPONENT_RIGHT || GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT)
            DummyBattleInterfaceFunc(gHealthboxSpriteIds[battler], TRUE);
        else
            DummyBattleInterfaceFunc(gHealthboxSpriteIds[battler], FALSE);

        if (!IsOnPlayerSide(battler))
        {
            if (GetMonData(GetBattlerMon(battler), MON_DATA_HP) == 0)
                SetHealthboxSpriteInvisible(healthboxSpriteId);
        }
        else if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
        {
            if (!IsValidForBattle(GetBattlerMon(battler)))
                SetHealthboxSpriteInvisible(healthboxSpriteId);
        }
    }
}

static void CreateCaughtMonSprite(void)
{
    SetMultiuseSpriteTemplateToPokemon(GetMonData(GetBattlerMon(gBattlerTarget), MON_DATA_SPECIES), GetBattlerPosition(gBattlerTarget));
    gBattlerSpriteIds[gBattlerTarget] = CreateSprite(&gMultiuseSpriteTemplate, DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, GetBattlerSpriteSubpriority(gBattlerTarget));
    gSprites[gBattlerSpriteIds[gBattlerTarget]].oam.paletteNum = gBattlerTarget;
    gSprites[gBattlerSpriteIds[gBattlerTarget]].callback = SpriteCallbackDummy;
    gSprites[gBattlerSpriteIds[gBattlerTarget]].data[0] = gBattlerTarget;
    gSprites[gBattlerSpriteIds[gBattlerTarget]].data[2] = GetMonData(GetBattlerMon(gBattlerTarget), MON_DATA_SPECIES);

    StartSpriteAnim(&gSprites[gBattlerSpriteIds[gBattlerTarget]], 0);

    gSprites[gBattlerSpriteIds[gBattlerTarget]].invisible = FALSE;
}
