/* Copyright 2021 the SumatraPDF project authors (see AUTHORS file).
   License: GPLv3 */

#include "utils/BaseUtil.h"
#include "utils/ScopedWin.h"
#include "utils/WinDynCalls.h"
#include "utils/CryptoUtil.h"
#include "utils/DirIter.h"
#include "utils/Dpi.h"
#include "utils/FileUtil.h"
#include "utils/FileWatcher.h"
#include "utils/GuessFileType.h"
#include "utils/HtmlParserLookup.h"
#include "utils/HttpUtil.h"
#include "utils/SquareTreeParser.h"
#include "utils/ThreadUtil.h"
#include "utils/UITask.h"
#include "utils/WinUtil.h"
#include "utils/GdiPlusUtil.h"
#include "utils/Archive.h"

#include "wingui/WinGui.h"
#include "wingui/Layout.h"
#include "wingui/Window.h"
#include "wingui/StaticCtrl.h"
#include "wingui/ButtonCtrl.h"
#include "wingui/TreeModel.h"
#include "wingui/TreeCtrl.h"
#include "wingui/SplitterWnd.h"
#include "wingui/LabelWithCloseWnd.h"
#include "wingui/FrameRateWnd.h"
#include "wingui/TooltipCtrl.h"
#include "wingui/DropDownCtrl.h"
#include "wingui/TabsCtrl.h"

#include "Annotation.h"
#include "DisplayMode.h"
#include "Controller.h"
#include "EngineBase.h"
#include "EngineAll.h"
#include "PdfCreator.h"
#include "SettingsStructs.h"
#include "GlobalPrefs.h"
#include "ChmModel.h"
#include "PalmDbReader.h"
#include "EbookBase.h"
#include "EbookDoc.h"
#include "MobiDoc.h"
#include "DisplayModel.h"
#include "FileHistory.h"
#include "PdfSync.h"
#include "RenderCache.h"
#include "ProgressUpdateUI.h"
#include "TextSelection.h"
#include "TextSearch.h"
#include "AppColors.h"
#include "SumatraPDF.h"
#include "Notifications.h"
#include "WindowInfo.h"
#include "TabInfo.h"
#include "UpdateCheck.h"
#include "resource.h"
#include "Commands.h"
#include "Flags.h"
#include "AppPrefs.h"
#include "AppTools.h"
#include "AppUtil.h"
#include "Canvas.h"
#include "Caption.h"
#include "CrashHandler.h"
#include "ExternalViewers.h"
#include "Favorites.h"
#include "FileThumbnails.h"
#include "Menu.h"
#include "Print.h"
#include "SearchAndDDE.h"
#include "Selection.h"
#include "StressTesting.h"
#include "SumatraAbout.h"
#include "SumatraDialogs.h"
#include "SumatraProperties.h"
#include "TableOfContents.h"
#include "Tabs.h"
#include "Toolbar.h"
#include "Translations.h"
#include "uia/Provider.h"
#include "Version.h"
#include "SumatraConfig.h"
#include "EditAnnotations.h"

#include "utils/Log.h"


#define _(...)

#include "../src/EngineMupdf.cpp"

                                           _( - LoadDocument                                                                                       )
                                           _(   - WindowInfo* LoadDocument(LoadArgs& args)                                                         )
                                           _(     - CreateControllerForEngine | CreateControllerForFile                                            )
                                           _(       - CreateEngine                                                                                 )
                                           _(         - CreateEngineForKind                                                                        )
                                           _(           - CreateEngineMupdfFromFile                                                                )
#define Monolith_EngineMupdf_RenderPage0   _(             - EngineMupdf-- - Lib : engines > EngineMupdf.cpp > Monolith_EngineMupdf_RenderPage      )
                                           _(               - class EngineMupdf : public EngineBase                                                )
                                           _(           - CreateEngineDjVuFromFile                                                                 )
                                           _(           - CreateEngineImageFromFile                                                                )
                                           _(           - CreateEngineImageDirFromFile                                                             )
                                           _(           - CreateEngineCbxFromFile                                                                  )
                                           _(           - CreateEnginePsFromFile                                                                   )
                                           _(           - CreateEngineChmFromFile                                                                  )
                                           _(           - CreateEngineEpubFromFile                                                                 )
                                           _(           - CreateEngineFb2FromFile                                                                  )
                                           _(           - CreateEngineMobiFromFile                                                                 )
                                           _(           - CreateEnginePdbFromFile                                                                  )
                                           _(     - DisplayModel                                                                                   )                                           
                                           _( - EngineBase                                                                                         )
                                           _(   - RenderPage=0 -> RenderedBitmap                                                                   )
