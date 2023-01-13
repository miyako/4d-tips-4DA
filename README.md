![version](https://img.shields.io/badge/version-19%2B-5682DF)
![platform](https://img.shields.io/static/v1?label=platform&message=mac-intel%20|%20mac-arm%20|%20win-64&color=blue)
[![license](https://img.shields.io/github/license/miyako/4d-tips-4DA)](LICENSE)

## ユーザーフォーム

v2004では**ユーザーフォーム**が利用できるようになりました。ユーザーフォームは，テーブル入出力フォームをカスタマイズした派生フォームで，テーブル入出力フォームの代わりに使用したり，簡易版のフォームエディターで修正したりすることができます。

* [\_o_CREATE USER FORM](https://doc.4d.com/4Dv19/4D/19.5/o-CREATE-USER-FORM.301-6136499.ja.html)

* [\_o_EDIT FORM](https://doc.4d.com/4Dv19/4D/19.5/o-EDIT-FORM.301-6136464.ja.html)

* [FORM SET INPUT](https://doc.4d.com/4Dv19/4D/19.5/FORM-SET-INPUT.301-6136695.ja.html)

* [FORM SET OUTPUT](https://doc.4d.com/4Dv19/4D/19.5/FORM-SET-OUTPUT.301-6136701.ja.html)

**注記**: 過去バージョンのドキュメントは[livedoc.4d.com](https://livedoc.4d.com)または[library.4d-japan.com](https://library.4d-japan.com/REFERENCE/)で参照することができます。

* [ユーザフォームの概要](https://livedoc.4d.com/--14.4/-/-.300-2511952.ja.html)

ユーザーフォームの仕組みは，**v18で廃止予定**となりました。

## ダイナミックフォーム

v17では，入出力フォーム・ダイアログ・サブフォームにドキュメントのパスまたはオブジェクトが指定できるようになりました。そのようなフォームは，事前にフォームエディターで作成したものではなく，動的に構築されたものであるという意味で，ダイナミックフォームと呼ばれます。JSON形式でスキーマ定義されているためにJSONフォームと呼ばれることもあります。

* [ダイナミックフォーム](https://doc.4d.com/4Dv19/4D/19/Dynamic-Forms.300-5416668.ja.html)

v19では，デザインモードのフォームエディターを起動するコマンドが追加されました。

* [FORM EDIT](https://doc.4d.com/4Dv19/4D/19.5/FORM-EDIT.301-6137414.ja.html)

[\_o_EDIT FORM](https://doc.4d.com/4Dv19/4D/19.5/o-EDIT-FORM.301-6136464.ja.html)とは違い，コンパイルされたアプリケーションで任意のフォームを開くことはできません。ダイナミックフォームは自由にフォームをカスタマイズできるという点ではユーザーフォームに代わるものですが，**フォームエディターのグラフィカルユーザーインタフェースを使用してユーザーが直接フォームをカスタマイズするというコンセプトに代わるものではない**ことに留意する必要があります。

## .4DAファイル

v2004でフォームを作成すると`.4DB`ストラクチャファイルと一緒に`.4DA`ファイルが作成されます。`.4DA`ファイルには，ユーザーフォームの情報が記録されています。ファイル拡張子は**4**th **D**imension **A**lternate Structure File（代替ストラクチャファイル）であることを意味します。

## 移行プラン

ダイナミックフォームを使用すれば，プログラミングでオブジェクトを構築したり，JSONファイルを編集したりすることにより，フォームをカスタマイズすることができます。前述したように，簡易版フォームエディターでフォームを修正することはできなくなりました。

ユーザーがカスタマイズした派生フォームは，`.4DA`ファイルにバイナリ形式で保存されています。このファイルの構造はストラクチャファイルと似ていますが，フォーム（`FO4D`）リソース以外が存在しないため，拡張子を`.4DB`に変更して開こうとすると，「パスワードテーブルが壊れています」というエラーが返されます。また，v2004のストラクチャをv18以降で開くことはできません。

<img width="480" alt="" src="https://user-images.githubusercontent.com/1725068/212257630-68771bf2-6664-4c95-896d-2e9f105565fa.png">

`.4DA`ファイルの読み書きには，プラグインSDKの内部リソースマネージャー（`PA_OpenResFile`など）が必要です。内部リソースはMacOSやAltura Mac2Winのリソース管理と概念的に似ていますが，独自の実装であり，標準コマンド（[Open resource file](https://doc.4d.com/4Dv19/4D/19.5/Open-resource-file.301-6137346.ja.html)など）では代用できません。



