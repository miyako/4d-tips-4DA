![version](https://img.shields.io/badge/version-19%2B-5682DF)
![platform](https://img.shields.io/static/v1?label=platform&message=mac-intel%20|%20mac-arm%20|%20win-64&color=blue)
[![license](https://img.shields.io/github/license/miyako/4d-tips-4DA)](LICENSE)

## ユーザーフォーム

v2004では**ユーザーフォーム**が利用できるようになりました。ユーザーフォームは，テーブル入出力フォームをカスタマイズした派生フォームで，テーブル入出力フォームの代わりに使用したり，簡易版のフォームエディターで修正したりすることができます。

テーブル入出力フォームのプロパティ「ユーザーによる更新可」を有効にすると，プロパティリストのグループ毎にロックアイコンが表示され，ユーザーフォームが作成できるようになります。ロックを解除したプロパティは，簡易版のフォームエディターでユーザーが変更できます。また図形や画像の追加は常にできます。

ユーザーフォームを作成すると，オリジナルのフォームはロックされます。ロックを解除すると，それまでに作成したユーザーフォームは使用できなくなります。`.4DA`ファイルには差分が記録されているわけではなく，完全なフォームが`FO4D`リソースとして保存されていますが，元のフォームを変更することは，派生したユーザーフォームを無効化する行為であると解釈されます。

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

ユーザーがカスタマイズした派生フォームは，`.4DA`ファイルにバイナリ形式で保存されています。このファイルの構造はストラクチャファイルと似ていますが，識別子（`FO4U`）およびフォーム（`FO4D`）リソース以外はデータが存在しないため，拡張子を`.4DB`に変更して開こうとすると，「パスワードテーブルが壊れています」というエラーが返されます。

<img width="480" alt="" src="https://user-images.githubusercontent.com/1725068/212257630-68771bf2-6664-4c95-896d-2e9f105565fa.png">

v19/18で開くことができる（つまり直接アップグレードすることができる）最古バージョンはv13です。v2004のストラクチャファイルは，一旦，v13を経由する必要があります。

* [以前のバージョンからのデータベースの変換](https://doc.4d.com/4Dv19/4D/19/Converting-databases-from-previous-versions.300-5416699.ja.html)
* [library.4d-japan.com](https://library.4d-japan.com/PRODUCTS/4D/Archives/v13_Line/)

### ステップ①

`.4DB`ファイルをv13以降にコンバートする

`.4DA`ファイルの読み書きには，プラグインSDKの[内部リソースマネージャー](https://developer.4d.com/4D-Plugin-SDK/CMU84573.HTM)（`PA_OpenResFile`など）が必要です。内部リソースはMacOSやAltura Mac2Winのリソース管理と概念的に似ていますが，独自の実装であり，標準コマンド（[Open resource file](https://doc.4d.com/4Dv19/4D/19.5/Open-resource-file.301-6137346.ja.html)など）では代用できません。

v19/18のSQL（下記）または[PA_CreateResFile](https://developer.4d.com/4D-Plugin-SDK/CMU84569.HTM)で作成した`.4DB`にv2004やv13のリソースを書き込むと「`PR4D`リソースがダメージを受けています」というエラーになり，修復ができません。

```sql
CREATE DATABASE IF NOT EXISTS DATAFILE :$path;
USE DATABASE DATAFILE :$path AUTO_CLOSE;--set PR4D
USE DATABASE SQL_INTERNAL;
```
<img width="260" alt="" src="https://user-images.githubusercontent.com/1725068/212609956-9ec84354-baa2-47f3-a8e5-bace629c2214.png">

リソースを移植する対象はファイルメニューから作成した標準のストラクチャファイルでなければなりません。ただし，元のストラクチャとは別の`.4DB`に`.4DA`のリソースを移植すると，`CC4D`リソースの参照が合わないため，オブジェクトメソッド・フォームメソッド・プロジェクトメソッドがオーファンになります。メニューバー・スタイルシート・ヘルプTipsなども同様です。

### ステップ②

`.4DA`から取り出した`FO4D`内部リソースを`.4DB`にコピーする

v13以降にコンバートしたストラクチャであれば，デザインモードで開くことができますが，コピーしたフォームはエクスプローラーに表示されません。移植したユーザーフォームは，テーブルに参照されていないオーファンフォームとなります。

### ステップ③

MSCでアプリケーションを修復し，オーファンフォームを炙り出します。v13でコンバートした場合，ピクチャライブラリの番号が符号反転し，表示されないかもしれません。また，QuickDraw画像（PICT形式）が表示されないという問題もあります（macOSのFinderや32-bit版の4Dで変換することができます）。とはいえ，この方法でユーザーフォームをサルベージすることができます。

### ステップ④

サルベージしたユーザーフォームは，通常のプロジェクトフォームやテーブルフォームと同じように編集することができます。v18以前の32-bit版であれば[FORM Convert to dynamic](https://doc.4d.com/4Dv19/4D/19.5/FORM-Convert-to-dynamic.301-6136687.ja.html)コマンドでJSONフォームに変換することができます。あるいは，一括してプロジェクトモードに移行できるかもしれません。

## 例題

v2004でユーザーフォームを作成します。

<img src="https://user-images.githubusercontent.com/1725068/212602587-e8e53b40-c9df-49c5-a5a7-9938f4839d51.png" width="800" />

v13にコンバートします。
<img src="https://user-images.githubusercontent.com/1725068/212603785-a80ed4b6-e71b-4aed-a18f-6f744e951ca6.png" width="800" />

v13の`.4DB`をクローンし，v2004の`.4DA`からリソースを移植します。

```4d
$source:=Folder(fk resources folder).folder("v2004").file("test.4DA")
$target:=Folder(fk resources folder).folder("v13").file("test.4DB")

$clone:=Folder(fk desktop folder).file("clone.4DB")

If (Not($clone.exists))
	$clone:=$target.copyTo($clone.parent; $clone.fullName)
	$status:=Clone structure file($source.platformPath; $clone.platformPath)
End if 
```

<img width="662" alt="" src="https://user-images.githubusercontent.com/1725068/212604597-a6506115-882d-474c-a413-6fd3d5aeab9e.png">

クローンした`.4DB`をv19で開きます。

<img width="480" alt="" src="https://user-images.githubusercontent.com/1725068/212604850-99910450-5df0-49c3-914f-8d2c30ff13b2.png">

<img width="480" alt="" src="https://user-images.githubusercontent.com/1725068/212604888-7d37b65a-bee3-491c-ab1b-b649c6dbcb92.png">

MSCでアプリケーションを検査すると「リンクのないフォーム」が検出されます。これは，ユーザーフォームをテーブルフォーム（`TF4D`）ではなく無所属のフォーム（`FO4D`）としてストラクチャに追加しているためです。

<img width="464" alt="" src="https://user-images.githubusercontent.com/1725068/212605106-6431df64-6bf9-468c-b352-75f09d8ceab5.png">

MSCでアプリケーションを修復すると「リンクのないフォーム」がオーファンプロジェクトフォームとして復活します。IDが再利用されていなければ，オリジナルフォームのロックを解除したことで消滅した「幻」のフォームも復活します。

<img width="711" alt="" src="https://user-images.githubusercontent.com/1725068/212605195-97f7e20f-2117-4de2-bbf7-b0c88f6f1392.png">

使用したプラグインは[Releases](https://github.com/miyako/4d-tips-4DA/releases)からダウンロードできます。
