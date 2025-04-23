#ifndef LIBRETRO_CORE_OPTIONS_INTL_H__
#define LIBRETRO_CORE_OPTIONS_INTL_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* https://support.microsoft.com/en-us/kb/980263 */
#pragma execution_character_set("utf-8")
#pragma warning(disable:4566)
#endif

#include <libretro.h>

/*
 ********************************
 * VERSION: 1.3
 ********************************
 *
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_JAPANESE */

/* RETRO_LANGUAGE_FRENCH */

/* RETRO_LANGUAGE_SPANISH */

/* RETRO_LANGUAGE_GERMAN */

/* RETRO_LANGUAGE_ITALIAN */

/* RETRO_LANGUAGE_DUTCH */

/* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */

/* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */

/* RETRO_LANGUAGE_RUSSIAN */

/* RETRO_LANGUAGE_KOREAN */

/* RETRO_LANGUAGE_CHINESE_TRADITIONAL */

/* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
struct retro_core_option_definition option_defs_chs[] = {
   {
      "gpsp_bios",
      "BIOS",
      "选择BIOS文件。官方BIOS必须由用户提供，使用非官方（或者内置）BIOS有些游戏可能会有兼容性问题。为达到最佳效果请使用任天堂官方BIOS。",
      {
         { "auto",      "自动选择" },
         { "builtin",   "内置BIOS" },
         { "official",  "原始BIOS" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "gpsp_boot_mode",
      "启动模式",
      "选择是否在游戏之前启动到BIOS。两种模式没有太大的不同。",
      {
         { "game",      "启动到游戏" },
         { "bios",      "启动到BIOS" },
         { NULL, NULL },
      },
      "game"
   },
#if defined(HAVE_DYNAREC)
   {
      "gpsp_drc",
      "动态重编译",
      "动态重编译CPU指令为本地指令。可以大幅提高性能，但是会降低精度。",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "enabled"
   },
#endif
   {
      "gpsp_sprlim",
      "无视角色限制",
      "移除原始硬件的每条扫描线上的角色数限制。有些游戏可能依赖此限制才能正常渲染（例如隐藏某些角色）。",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "gpsp_rtc",
      "实时时钟支持",
      "设置卡带的实时时钟支持。自动模式使用ROM数据库的信息，适用于大多数商业游戏。对于自制游戏或者修改版游戏，可能须要强制设置实时时钟。",
      {
         { "auto", "自动" },
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "gpsp_serial",
      "联机设置",
      "配置联机功能。自动模式会为大多数已知游戏选择合适的设置。",
      {
         { "auto",     "自动" },
         { "disabled", "禁用" },
         { "rfu",      "GBA无线适配器" },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "gpsp_rumble",
      "震动支持",
      "设置卡带的震动功能。自动模式使用ROM数据库的信息，适用于大多数商业游戏。对于支持震动的自制游戏或者修改版游戏，可能须要强制设置震动。如果你不喜欢震动，也可以强制禁用。",
      {
         { "auto", "自动" },
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "auto"
   },
   {
      "gpsp_frameskip",
      "跳帧",
      "跳过一定帧数以避免音频缓冲欠载（爆音），通过牺牲视频流畅度来提高性能。‘自动’模式使用前端推荐的帧数；‘自动（阈值）’模式使用‘跳帧阈值(%)’设置；‘固定间隔’模式使用‘跳帧间隔’设置。",
      {
         { "disabled",       NULL },
         { "auto",           "自动" },
         { "auto_threshold", "自动（阈值）" },
         { "fixed_interval", "固定间隔" },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "gpsp_frameskip_threshold",
      "跳帧阈值(%)",
      "当‘跳帧’设为‘自动（阈值）’时， 指定音频缓冲区占用阈值（百分比），低于该阈值时帧将被跳过。值越高爆音的风险越低，丢帧越频繁。",
      {
         { "15", NULL },
         { "18", NULL },
         { "21", NULL },
         { "24", NULL },
         { "27", NULL },
         { "30", NULL },
         { "33", NULL },
         { "36", NULL },
         { "39", NULL },
         { "42", NULL },
         { "45", NULL },
         { "48", NULL },
         { "51", NULL },
         { "54", NULL },
         { "57", NULL },
         { "60", NULL },
         { NULL, NULL },
      },
      "33"
   },
   {
      "gpsp_frameskip_interval",
      "跳帧间隔",
      "当‘跳帧’设为‘固定间隔’时，此值指定渲染一帧后丢弃多少帧，例如： '0' = 60fps, '1' = 30fps, '2' = 15fps, 等等。",
      {
         { "0",  NULL },
         { "1",  NULL },
         { "2",  NULL },
         { "3",  NULL },
         { "4",  NULL },
         { "5",  NULL },
         { "6",  NULL },
         { "7",  NULL },
         { "8",  NULL },
         { "9",  NULL },
         { "10", NULL },
         { NULL, NULL },
      },
      "1"
   },
   {
      "gpsp_color_correction",
      "色彩校正",
      "调整输出色彩以匹配真实GBA硬件的显示效果。",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "gpsp_frame_mixing",
      "帧间混合",
      "通过对当前帧和上一帧执行一个50:50的的混合来模拟LCD鬼影效果。该功能对于某些使用LCD鬼影现象来实现透明效果的游戏是必需的（例如《零式赛车》、《我们的太阳》系列）。",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "gpsp_turbo_period",
      "连发键间隔",
      "指定按住A/B连发键时，连发的间隔（帧数）。",
      {
         { "4",   NULL },
         { "5",   NULL },
         { "6",   NULL },
         { "7",   NULL },
         { "8",   NULL },
         { "9",   NULL },
         { "10",  NULL },
         { "11",  NULL },
         { "12",  NULL },
         { "13",  NULL },
         { "14",  NULL },
         { "15",  NULL },
         { "16",  NULL },
         { "17",  NULL },
         { "18",  NULL },
         { "19",  NULL },
         { "20",  NULL },
         { "21",  NULL },
         { "22",  NULL },
         { "23",  NULL },
         { "24",  NULL },
         { "25",  NULL },
         { "26",  NULL },
         { "27",  NULL },
         { "28",  NULL },
         { "29",  NULL },
         { "30",  NULL },
         { "31",  NULL },
         { "32",  NULL },
         { "33",  NULL },
         { "34",  NULL },
         { "35",  NULL },
         { "36",  NULL },
         { "37",  NULL },
         { "38",  NULL },
         { "39",  NULL },
         { "40",  NULL },
         { "41",  NULL },
         { "42",  NULL },
         { "43",  NULL },
         { "44",  NULL },
         { "45",  NULL },
         { "46",  NULL },
         { "47",  NULL },
         { "48",  NULL },
         { "49",  NULL },
         { "50",  NULL },
         { "51",  NULL },
         { "52",  NULL },
         { "53",  NULL },
         { "54",  NULL },
         { "55",  NULL },
         { "56",  NULL },
         { "57",  NULL },
         { "58",  NULL },
         { "59",  NULL },
         { "60",  NULL },
         { "61",  NULL },
         { "62",  NULL },
         { "63",  NULL },
         { "64",  NULL },
         { "65",  NULL },
         { "66",  NULL },
         { "67",  NULL },
         { "68",  NULL },
         { "69",  NULL },
         { "70",  NULL },
         { "71",  NULL },
         { "72",  NULL },
         { "73",  NULL },
         { "74",  NULL },
         { "75",  NULL },
         { "76",  NULL },
         { "77",  NULL },
         { "78",  NULL },
         { "79",  NULL },
         { "80",  NULL },
         { "81",  NULL },
         { "82",  NULL },
         { "83",  NULL },
         { "84",  NULL },
         { "85",  NULL },
         { "86",  NULL },
         { "87",  NULL },
         { "88",  NULL },
         { "89",  NULL },
         { "90",  NULL },
         { "91",  NULL },
         { "92",  NULL },
         { "93",  NULL },
         { "94",  NULL },
         { "95",  NULL },
         { "96",  NULL },
         { "97",  NULL },
         { "98",  NULL },
         { "99",  NULL },
         { "100", NULL },
         { "101", NULL },
         { "102", NULL },
         { "103", NULL },
         { "104", NULL },
         { "105", NULL },
         { "106", NULL },
         { "107", NULL },
         { "108", NULL },
         { "109", NULL },
         { "110", NULL },
         { "111", NULL },
         { "112", NULL },
         { "113", NULL },
         { "114", NULL },
         { "115", NULL },
         { "116", NULL },
         { "117", NULL },
         { "118", NULL },
         { "119", NULL },
         { "120", NULL },
         { NULL, NULL },
      },
      "4"
   },
   { NULL, NULL, NULL, {{0}}, NULL },
};


/* RETRO_LANGUAGE_ESPERANTO */

/* RETRO_LANGUAGE_POLISH */

/* RETRO_LANGUAGE_VIETNAMESE */

/* RETRO_LANGUAGE_ARABIC */

/* RETRO_LANGUAGE_GREEK */

/* RETRO_LANGUAGE_TURKISH */

/* RETRO_LANGUAGE_SLOVAK */

/* RETRO_LANGUAGE_PERSIAN */

/* RETRO_LANGUAGE_HEBREW */

/* RETRO_LANGUAGE_ASTURIAN */

#ifdef __cplusplus
}
#endif

#endif
