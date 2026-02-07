= 第二章　地図とピンと、見知らぬ人々

== 地図の上のピン

Swiftful Thinkingの「Map App」プレイリスト、全二十二話。

翔はその第一話を再生した瞬間から、Todoアプリとはまったく異なる世界が広がることを直感した。Todoアプリは「リストにテキストを並べる」UIだった。地図アプリは違う。現実世界の空間を、コードで操作する。

Nickの落ち着いた声がイヤホンから流れる。まず、SwiftUIで地図を表示する。

//list[map_basic][MapKitの基本：地図を表示する][swift]{
import SwiftUI
import MapKit

struct MapView: View {
    // カメラの初期位置を東京駅に設定
    @State private var cameraPosition: MapCameraPosition = .region(
        MKCoordinateRegion(
            center: CLLocationCoordinate2D(
                latitude: 35.6812,
                longitude: 139.7671
            ),
            span: MKCoordinateSpan(
                latitudeDelta: 0.05,
                longitudeDelta: 0.05
            )
        )
    )

    var body: some View {
        Map(position: $cameraPosition)
    }
}
//}

@<code>{import MapKit}——Appleが提供する地図フレームワークを読み込む宣言。これだけで、Apple Mapsと同じ地図エンジンが自分のアプリで使える。

@<code>{MKCoordinateRegion}で地図の表示範囲を指定する。@<code>{center}が中心座標、@<code>{span}が表示範囲の広さ。@<code>{latitudeDelta}と@<code>{longitudeDelta}の値が小さいほどズームイン、大きいほどズームアウトになる。

翔はプレビューを見た。MacBook Airの画面に、東京駅周辺の地図が表示されている。道路、建物、駅名——すべてがリアルタイムにレンダリングされている。指でピンチすればズームし、ドラッグすればスクロールする。

たった二十行程度のコードで、地図アプリの基盤ができた。

「これ、Googleマップみたいなことができるってこと？」

翔は思わず声に出した。もちろんGoogleマップほどの機能は実装できないが、基本的な地図表示、ピンの配置、ユーザーの現在地追跡、経路検索——すべてMapKitに含まれている。Appleが無料で提供しているフレームワークだ。

次に、地図上にピンを立てる。チュートリアルでは「ランドマーク」として観光地の情報を表示するアプリを作る。まず、場所のデータモデルを定義する。

//list[location_model][場所のデータモデル][swift]{
struct Location: Identifiable, Equatable {
    let id = UUID()
    let name: String
    let cityName: String
    let coordinates: CLLocationCoordinate2D
    let description: String

    // Equatableに準拠するための比較メソッド
    static func == (lhs: Location, rhs: Location) -> Bool {
        lhs.id == rhs.id
    }
}
//}

@<code>{CLLocationCoordinate2D}——Core Locationフレームワークの型で、緯度（latitude）と経度（longitude）を保持する構造体。地球上のあらゆる場所を、この二つの数値で特定できる。

翔はこの型名を見て、デザイナーとしての記憶が蘇った。Illustratorでオブジェクトを配置するとき、X座標とY座標を指定する。それとまったく同じだ。ただし、Illustratorの座標系はアートボードの左上が原点で、右にX、下にYが増える。地球の座標系は、赤道が緯度ゼロ、グリニッジ子午線が経度ゼロ。スケールは違うが、「二つの数値で位置を決める」という本質は同じだった。

そしてMap上に@<code>{Annotation}を配置する。

//list[map_annotation][地図にAnnotationを配置する][swift]{
Map(position: $cameraPosition) {
    ForEach(locations) { location in
        Annotation(location.name, coordinate: location.coordinates) {
            VStack(spacing: 0) {
                Image(systemName: "map.circle.fill")
                    .resizable()
                    .scaledToFit()
                    .frame(width: 30, height: 30)
                    .font(.headline)
                    .foregroundStyle(.white)
                    .padding(6)
                    .background(.blue)
                    .clipShape(Circle())

                Image(systemName: "triangle.fill")
                    .resizable()
                    .scaledToFit()
                    .frame(width: 10, height: 10)
                    .foregroundStyle(.blue)
                    .rotationEffect(Angle(degrees: 180))
                    .offset(y: -3)
            }
        }
    }
}
//}

翔はプレビューを更新した。地図上に青い丸アイコンが表示され、その下に逆三角形のしっぽが付いている。まるで、Google Mapsのピンのような外観だ。しかしこれは、翔が——SwiftUIのコードとSF Symbolsだけで作った、完全にカスタムのピンだ。

デザイナーの血が騒いだ。

「色を変えよう。サイズも調整したい。影も付けたい」

翔はモディファイアを次々に追加していった。@<code>{.shadow()}、@<code>{.scaleEffect()}、@<code>{.animation()}。第一章で学んだモディファイアの知識が、ここで活きた。Todoアプリで覚えた技術が、地図アプリという新しい文脈で再利用できる。これがプログラミングの醍醐味なのだと、翔は体で理解し始めていた。


== 座標という名のデザイン

Swiftful Thinkingの地図アプリチュートリアルは、単なるUI構築にとどまらなかった。

場所のデータを管理する@<code>{ViewModel}の設計。地図のカメラをアニメーション付きで移動させる方法。タップした場所の詳細情報をシート表示する実装。翔はNickの動画を一つずつ追いかけ、コードを写経した。

特に翔の目を引いたのは、地図のカメラを特定の場所にアニメーション付きで移動させるコードだった。

//list[map_camera_animation][地図カメラのアニメーション移動][swift]{
// 選択した場所にカメラを移動する
func updateMapRegion(location: Location) {
    withAnimation(.easeInOut) {
        cameraPosition = .region(
            MKCoordinateRegion(
                center: location.coordinates,
                span: MKCoordinateSpan(
                    latitudeDelta: 0.01,
                    longitudeDelta: 0.01
                )
            )
        )
    }
}
//}

@<code>{withAnimation(.easeInOut)}で囲むだけで、地図のカメラ移動がなめらかなアニメーションになる。イージングカーブの指定まで、After Effectsのキーフレーム設定と同じ概念だ。

翔はこのチュートリアルを通じて、SwiftUIの@<b>{MVVMアーキテクチャ}に初めて触れた。

//note[MVVMアーキテクチャとは]{
MVVMは@<b>{Model-View-ViewModel}の略で、アプリのコードを三つの役割に分離する設計パターン。

@<b>{Model}：データそのもの。LocationやTodoItemのような構造体。

@<b>{View}：ユーザーが見る画面。SwiftUIのViewに相当する。

@<b>{ViewModel}：ModelとViewの間を仲介するクラス。データの取得・加工・状態管理を担う。Viewから直接Modelを操作せず、ViewModelを経由することで、コードの見通しが良くなる。

デザイン業界に例えるなら、Modelは「素材写真」、Viewは「完成したレイアウト」、ViewModelは「Illustratorの作業ファイル（.ai）」に相当する。素材を直接レイアウトに貼るのではなく、作業ファイルで加工・調整してから最終出力する——その構造と同じだ。
//}

Swiftful Thinkingの地図アプリでは、@<code>{LocationsViewModel}というクラスが登場した。

//list[locations_viewmodel][LocationsViewModel：地図アプリのViewModel][swift]{
class LocationsViewModel: ObservableObject {
    // 全ての場所データ
    @Published var locations: [Location]
    // 現在選択中の場所
    @Published var selectedLocation: Location
    // シートの表示状態
    @Published var showLocationDetail: Bool = false

    init() {
        let locations = LocationsDataService.locations
        self.locations = locations
        self.selectedLocation = locations.first!
    }

    // 次の場所に切り替える
    func nextButtonPressed() {
        guard let currentIndex = locations.firstIndex(
            where: { $0 == selectedLocation }
        ) else { return }

        let nextIndex = currentIndex + 1
        if locations.indices.contains(nextIndex) {
            selectedLocation = locations[nextIndex]
        } else {
            selectedLocation = locations.first!
        }
    }
}
//}

@<code>{@Published}は、値が変更されたときに自動的にViewに通知するプロパティラッパー。第一章で学んだ@<code>{@State}はView内部の状態管理だったが、@<code>{@Published}はクラス内のプロパティに使う。ViewModelの値が変わると、それを監視しているViewが自動的に再描画される。

翔はここで「データの流れ」を意識し始めた。第一章のTodoアプリでは@<code>{@State}ですべてを管理していたが、アプリが複雑になると、状態管理のロジックをViewの外に出す必要がある。それがViewModelの役割だ。

チュートリアルの地図アプリを完成させるのに、翔は二週間かかった。毎晩二時間、昼休みの三十分、通勤電車の往復一時間。合計すると四十時間近い学習時間だ。完成した地図アプリは、複数の観光地をリスト表示し、タップするとアニメーション付きで地図が移動し、詳細情報がシートで表示される。第一章のTodoアプリとは比べものにならない複雑さだった。

翔はiPhoneのシミュレータで地図アプリを動かしながら、ある衝動を感じた。

この進捗を、誰かに見せたい。


== 書籍が消えた言語

翔はSwiftUIの学習を続けるうちに、ある異変に気づいた。

書店のプログラミング書籍コーナーに足を運んだときのことだ。Python、JavaScript、Ruby、Go——さまざまなプログラミング言語の入門書や実践書が棚を埋め尽くしている。しかし、Swiftの棚は驚くほど薄かった。

数えてみると、Swift関連の書籍は五冊程度。しかもそのほとんどが二〇一九年か二〇二〇年の出版だった。二〇二一年以降に出版されたSwift/SwiftUI専門の書籍は、ほぼ見当たらない。

翔はその場でスマートフォンを取り出し、Amazonで検索した。「SwiftUI」で絞り込む。結果は同じだった。最新のものでも二〇二〇年。それ以降、SwiftUI専門の書籍はほとんど出版されていない。

なぜだ？

帰宅後、翔はその理由を調べた。

答えは単純で、そして残酷だった。@<b>{Swiftの言語仕様とSwiftUIのAPIは、毎年大きく変わる。}

Appleは毎年六月にWWDC（Worldwide Developers Conference）を開催し、SwiftとSwiftUIの大規模アップデートを発表する。新しい構文、新しいAPIが追加され、古いAPIはdeprecated（非推奨）になる。書籍の企画から出版までには半年から一年かかる。書籍が出版される頃には、その内容の一部がすでに古くなっている。

Swiftは@<b>{「進化が速すぎて書籍が追いつけない言語」}だったのだ。

翔は途方に暮れかけたが、調べていくうちに解決策を見つけた。

//note[Swift/SwiftUIの学習リソース事情]{
Swift/SwiftUIの学習で信頼できるリソースは、主に三つの系統がある。

@<b>{1. Apple公式ドキュメント}
 * 「The Swift Programming Language」：Swift言語そのものの公式リファレンス。Apple Developer サイトで無料公開されている。常に最新バージョンに更新される。
 * 「SwiftUI Tutorials」：第一章で翔が取り組んだLandmarksチュートリアル。
 * 「WWDC Sessions」：毎年のWWDCで発表されるセッション動画。新機能の解説が最も正確かつ詳細に語られる。

@<b>{2. 海外のYouTubeチャンネル}
 * Swiftful Thinking：翔が使っているチャンネル。体系的なブートキャンプ形式。
 * Sean Allen：実践的なアプリ開発のチュートリアル。
 * Paul Hudson（Hacking with Swift）：Swift言語の深い解説。

@<b>{3. 日本語の書籍・リソース}
 * 「Swift実践入門」（石川洋資・西山勇世 著）：Swift言語の基礎を日本語で学べる数少ない良書。ただし出版年に注意。
 * 「The Swift Programming Language」の日本語訳コミュニティ。
 * Qiita、Zennなどの技術ブログ記事（ただし投稿日の確認が必須）。

書籍で体系的に学ぶのが難しいぶん、@<b>{公式ドキュメント + YouTube + コミュニティ}の三本柱で学習を進めるのがSwift/SwiftUIの王道となっている。
//}

翔は「The Swift Programming Language」のページをブックマークした。英語だが、翻訳ツールを併用すれば読める。Swiftful Thinkingで手を動かし、疑問が出たら公式ドキュメントで確認する。そしてSwift言語の基礎を体系的に理解するために「Swift実践入門」も注文した。

書籍に頼れないという事実は、裏を返せば、@<b>{最新の情報に誰でもアクセスできる}ということでもあった。高額な専門書を買い揃えなくても、Apple公式のドキュメントとYouTubeがあれば学べる。翔のようなキャリアチェンジ組にとって、これは大きなアドバンテージだった。


== 一四〇文字の開発日記

ある夜、翔はシミュレータに映る地図アプリのスクリーンショットを撮った。

東京タワー、浅草寺、渋谷スクランブル交差点——チュートリアルのサンプルデータを日本の観光地に置き換えたものだ。地図上にカスタムのピンが立ち、タップするとシートが開いて詳細情報が表示される。

翔はXの投稿画面を開いた。第一章で志村さんに勧められて以来、学習の進捗をXに投稿する習慣がついていた。最初は恥ずかしかったが、志村さんの「アウトプットすると記憶に定着する」という言葉を信じて続けていた。

//quote{
Day 25：Swiftful Thinkingの地図アプリチュートリアル完走！MapKit + MVVMで観光地アプリを作りました。カスタムAnnotation、カメラアニメーション、シート表示まで実装。ViewModelでデータとUIを分離する設計パターンが少しわかってきた。 #SwiftUI #MapKit #iOS開発
//}

スクリーンショットを三枚添付して投稿する。地図の全体表示、ピンのクローズアップ、詳細シートの画面。

五分後。志村さんからいいねが付いた。そしてリプライ。

//quote{
@yukikawa_sho 25日でここまで来たのすごいですね。MVVMを意識できているのがいい。次はObservableマクロ（@Observable）も調べてみてください。@StateObjectや@ObservedObjectを使わずにもっとシンプルに書けるようになります。iOS 17以降の新しい書き方です。
//}

他にも反応があった。フォロワー二十人のアカウントが、五十人に増えていた。同じようにSwiftUIを学んでいる人、個人開発をしている人、現役のiOSエンジニア。翔の投稿に「いいね」や「リポスト」をしてくれる人が少しずつ増えている。

特に嬉しかったのは、翔と同じ時期にSwiftUIの学習を始めたらしいアカウントからのリプライだった。

//quote{
@yukikawa_sho 自分もSwiftful Thinkingで勉強中です！地図アプリのチュートリアルちょうどやるところだったので参考になります。お互い頑張りましょう！
//}

一人じゃない。

翔はその事実に、想像以上の力をもらった。デザイン会社のアシスタントとして、上司とクライアントの間で修正データを作る日々。その孤独な作業と対照的に、Xには同じ道を歩む仲間がいた。

翔はこの習慣に名前があることを、後になって知った。

@<b>{Build in Public。}

//note[Build in Publicとは]{
Build in Publicとは、プロダクトの開発過程をSNSやブログで@<b>{公開しながら}開発を進める手法。主にインディーハッカー（個人開発者）の間で広まった。

特徴：
 * 開発の進捗、失敗、学びをリアルタイムで共有する
 * フィードバックを早期に得られる
 * 同じ目標を持つ仲間とつながれる
 * 完成したときには既にユーザーやファンがいる状態を作れる
 * 自分自身のモチベーション維持にもなる

個人開発において、Build in Publicは「マーケティング」と「学習の記録」と「コミュニティ形成」を同時に行える強力な手法だ。翔が何気なく始めたXでの学習投稿は、まさにBuild in Publicそのものだった。
//}

翔はそれまで、デザインの仕事でSNSを「作品発表の場」として使ったことはあった。Behanceにポートフォリオを上げ、完成した美しい成果物だけを見せる。しかしBuild in Publicは違う。未完成でもいい。バグだらけでもいい。むしろ、@<b>{過程を見せること}に価値がある。

この考え方は、デザイン業界の「完成品だけを見せる」文化とは真逆だった。そして翔は、こちらの方が自分に合っていると感じた。


== Connpassと村田さん

十二月。

翔がSwiftUIの学習を始めて一ヶ月半が過ぎた。Xで学習記録を投稿し続ける中で、ある単語が頻繁にタイムラインに流れてくることに気づいた。

@<b>{Connpass}。

エンジニア向けのイベント・勉強会のプラットフォームらしい。「もくもく会」「LT会」「ハンズオン」——さまざまなイベントが毎日のように開催されている。翔はアカウントを作成し、「iOS」「SwiftUI」「個人開発」で検索してみた。

そこで見つけたのが、「個人開発者もくもく会」だった。

主催者は村田さんという方。プロフィールには「個人開発歴五年、リリースアプリ十二本」とある。毎月第二土曜日に、都内のカフェスペースで開催している。参加費は五百円（ドリンク代）。定員十名。

翔は迷わず参加ボタンを押した。中野と美咲のもくもく会に参加したときのことを思い出す。あのとき翔はデザイナーとして参加し、アイコンを作ることしかできなかった。今は違う。自分のXcodeプロジェクトを持っている。地図アプリのチュートリアルも完走した。

土曜日。会場は下北沢のカフェの二階。階段を上ると、八人ほどのエンジニアがMacBookを開いて作業していた。年齢層は二十代後半から四十代まで幅広い。

「あ、初めてですか？　村田です。よろしく」

村田さんは三十代前半に見えた。丸眼鏡にシャツ姿、穏やかな笑顔。名刺代わりにiPhoneの画面を見せてくれた。App Storeに並ぶ十二個のアプリアイコン。タスク管理、天気予報、読書記録、瞑想タイマー——ジャンルはバラバラだが、すべて村田さんが一人で開発しリリースしたものだという。

「柏——あ、雪川です。グラフィックデザイナーで、今SwiftUIを勉強しています。まだ一ヶ月半くらいなんですけど」

「デザイナーさん！」

村田さんの反応は、かつての中野と同じだった。

「デザインできるエンジニアって、めちゃくちゃ貴重なんですよ。エンジニアは機能を作れるけど、UIが残念なアプリ多いでしょ？　デザインのバックグラウンドがある人がSwiftUI書けるようになったら、最強ですよ」

翔は苦笑した。まだ「SwiftUIを書ける」と胸を張れるレベルではない。しかし、デザイナーとしての経験が「強み」として評価されるのは純粋に嬉しかった。デザイン会社では「アシスタント」という肩書が自分の価値のすべてだった。ここでは「デザインができる」というスキルが、別の意味を持つ。

もくもく会が始まると、各自がそれぞれのプロジェクトに取り組んだ。翔はSwiftful Thinkingの次のチュートリアルを進めようとしたが、周りの参加者の画面が気になった。

隣の席の女性は、植物の水やりリマインダーアプリを開発していた。ローカル通知とCore Dataを使っているらしい。向かいの男性は、カメラアプリに独自のフィルターを実装中。Core Imageというフレームワークを使うのだという。

翔が知らないフレームワーク、知らない技術が、ここにはごろごろ転がっていた。

休憩時間、村田さんが翔に話しかけてきた。

「雪川さん、Xで学習記録つけてるんでしょ？　見ましたよ。いいですね、あのペース。ところで、来週CA.swiftっていうLT会があるんだけど、興味ない？」

「LT会？」

「ライトニングトークの略。五分とか十分の短いプレゼンを何人かが順番にやるイベント。大手のIT企業が主催してて、プロのiOSエンジニアが発表するやつ」

翔の心臓が跳ねた。プロのiOSエンジニアの話を直接聞ける機会。

「行きます」

村田さんは満足そうに頷いた。ConnpassのイベントページのURLを共有してくれた。


== CA.swift #22

一週間後。渋谷の大手IT企業のオフィス。

「CA.swift #22 〜Swiftの進化を活かした技術基盤への挑戦〜」と題されたLT会の会場は、翔が想像していたよりもはるかに洗練されていた。

広いイベントスペースにモニターが並び、百人以上のエンジニアが着席している。翔は後方の席に座った。村田さんが隣に来てくれたので、少しだけ安心した。

「すごい人数ですね」

「CA.swiftは人気あるからね。大手の企業が主催するLT会は、技術レベルが高い分、学べることも多い。初心者でも参加して大丈夫だから、気楽に聞いてて」

最初のLTが始まった。発表者は、大手IT企業のシニアiOSエンジニア。テーマは「Swift Concurrencyを活用した非同期処理の設計パターン」。

スライドにコードが映し出された。

//list[async_await_basic][async/awaitの基本形][swift]{
// 非同期でデータを取得する関数
func fetchUserData() async throws -> User {
    let url = URL(string: "https://api.example.com/user")!
    let (data, response) = try await URLSession.shared.data(from: url)

    guard let httpResponse = response as? HTTPURLResponse,
          httpResponse.statusCode == 200 else {
        throw NetworkError.invalidResponse
    }

    return try JSONDecoder().decode(User.self, from: data)
}

// 呼び出し側
Task {
    do {
        let user = try await fetchUserData()
        print("ユーザー名: \(user.name)")
    } catch {
        print("エラー: \(error)")
    }
}
//}

@<code>{async}、@<code>{await}、@<code>{Task}、@<code>{throws}、@<code>{try}——翔にとってはほぼすべてが初見の単語だった。

発表者は流暢に説明を続ける。「@<code>{async/await}はSwift 5.5で導入された構造化並行性の基盤で、従来のクロージャベースの非同期処理と比べて……」

翔にはほとんど理解できなかった。

二人目の発表者のテーマは「SwiftUIのパフォーマンスチューニング」。三人目は「TCA（The Composable Architecture）を用いた大規模アプリの状態管理」。四人目は「Swift Macrosによるボイラープレートの削減」。

TCA？　Swift Macros？　聞いたこともない。

翔はメモ帳アプリを開き、知らない単語を片っ端から書き留めた。

@<b>{async/await}、@<b>{Swift Concurrency}、@<b>{URLSession}、@<b>{JSONDecoder}、@<b>{Actor}、@<b>{Sendable}、@<b>{TCA}、@<b>{Swift Macros}、@<b>{@Observable}、@<b>{Combine}、@<b>{Core Data}、@<b>{SwiftData}。

十五個以上の未知の技術用語。翔が知っているのは、@<code>{VStack}と@<code>{@State}と@<code>{List}くらいだ。自分が立っている場所と、プロのiOSエンジニアが立っている場所の距離を、翔はこの夜、初めて正確に測った。

//note[Swift Concurrencyとは]{
Swift Concurrency（構造化並行性）は、Swift 5.5で導入された非同期処理の仕組み。

@<b>{従来の方法}：コールバック（クロージャ）を入れ子にしていく。深くなると「コールバック地獄」と呼ばれる読みにくいコードになる。

@<b>{async/awaitの方法}：非同期処理を同期処理のように直線的に書ける。コードの可読性が格段に上がる。

@<code>{async}は「この関数は非同期です」という宣言。@<code>{await}は「この処理の完了を待ちます」というマーク。@<code>{Task}は非同期処理を実行するためのコンテナ。

翔が今すぐ理解する必要はないが、@<b>{APIからデータを取得する}（ネットワーク通信）はほぼすべてのアプリで必要な機能であり、その実装にはasync/awaitが使われる。将来、必ず向き合うことになる技術だ。
//}

LT会の後、懇親会があった。ビールとピザが振る舞われ、エンジニアたちが技術談義に花を咲かせている。翔は壁際で炭酸水を飲んでいた。六本木の言語交換ミートアップのときと同じだ。壁際の男。

しかし今回は違った。六本木のときは「何者でもない自分」だったが、今は「SwiftUIを学んでいる自分」がいる。小さくても、語れるものがある。

翔は勇気を出して、近くにいたエンジニアに話しかけた。

「あの、async/awaitのLT、すごかったですね。自分はまだSwiftUI始めて二ヶ月くらいの初心者なんですけど」

「二ヶ月？　最近始めたんですね。SwiftUIから入るのは正解ですよ。UIKitは学習コストが高いんで」

「UIKit？」

「SwiftUIの前にあったUIフレームワーク。StoryboardっていうビジュアルエディタでUIを作るんだけど、SwiftUIと比べるとかなり冗長で」

翔はまた一つ、知らない単語を仕入れた。UIKit。Storyboard。SwiftUIの前の世界。

会場を出るとき、翔は空を見上げた。十二月の夜空は澄んでいて、星はほとんど見えないが、ビルの灯りが代わりに光っている。

「いつか、あのステージで発表する」

翔は誰にも聞こえない声で呟いた。それは決意というよりも、予感だった。


== バージョン管理という地図

翌週のもくもく会。翔がコードを書いていると、村田さんが画面を覗き込んできた。

「雪川さん、GitHubやってる？」

「GitHub……名前は聞いたことありますけど、使ったことはないです」

「うーん、そろそろやった方がいいと思う。コードのバージョン管理。今の状態だと、何か壊したときに戻れないでしょ」

図星だった。翔は何度か、コードを修正しているうちにアプリが動かなくなり、元に戻せなくなった経験がある。仕方なくプロジェクト全体を削除して、最初からやり直したことも一度や二度ではない。

「Gitっていうバージョン管理ツールがあって、GitHubはそのコードをインターネット上に保存できるサービス。エンジニアなら全員使ってるよ」

村田さんは翔のMacBookの横に座り、説明を始めた。

「デザイナーさんならわかると思うんだけど、Illustratorで作業してるとき、重要な変更の前に『別名保存』するでしょ？　final.ai、final_v2.ai、final_v2_本当のfinal.ai、みたいな」

翔は笑った。まさにその通りだ。デザイン業界の「ファイル名地獄」は有名な問題だ。

「Gitは、それを賢くやってくれるツール。ファイルを複製するんじゃなくて、『変更の差分』だけを記録していく。いつでも好きな時点に戻れるし、誰がいつ何を変えたかも全部わかる」

//list[git_basic_commands][Gitの基本コマンド][shell]{
# 1. プロジェクトでGitを使い始める（初期化）
git init

# 2. 変更したファイルを「次のコミット」に含める
git add .

# 3. 変更を記録する（コミット）= セーブポイント
git commit -m "Todoアプリの削除機能を追加"

# 4. GitHubのリモートリポジトリを登録する
git remote add origin https://github.com/username/my-todo-app.git

# 5. コミットをGitHubに送る（プッシュ）
git push -u origin main
//}

村田さんが一つずつ教えてくれた。

@<code>{git init}——「このフォルダをGitで管理します」という宣言。プロジェクトの最初に一度だけ実行する。

@<code>{git add .}——「変更したファイルを、次の記録に含めます」という操作。ピリオドは「全部」の意味。

@<code>{git commit -m "メッセージ"}——「この状態を記録します」。ゲームのセーブポイントに相当する。メッセージには「何をしたか」を書く。

@<code>{git push}——「記録をGitHubに送ります」。これで、インターネット上にコードのバックアップができる。

//note[Gitとは何か：エンジニア必須の理由]{
@<b>{Git}は、ソースコードの変更履歴を管理するための@<b>{分散型バージョン管理システム}。二〇〇五年にLinuxカーネルの開発者であるリーナス・トーバルズが開発した。

@<b>{なぜエンジニアに必須なのか：}
 1. @<b>{履歴管理}：いつ、誰が、何を変えたかを完全に記録する。「三日前の状態に戻す」が一瞬でできる。
 2. @<b>{協業}：複数人が同時に同じプロジェクトを編集しても、変更を統合（マージ）できる。
 3. @<b>{バックアップ}：GitHubにpushしておけば、PCが壊れてもコードは失われない。
 4. @<b>{ポートフォリオ}：GitHubのリポジトリは、エンジニアの「作品集」として就職活動でも評価される。

デザイナーにとってのAdobe Creative Cloudと同じように、エンジニアにとってのGitHub/Gitは@<b>{インフラ}だ。使えることが前提の世界。
//}

翔はその場で、GitHubアカウントを作成した。ユーザー名は「yukikawa-sho」。プロフィール写真には、自分がデザインしたIgnoreのアイコンを設定した。

そして、Todoアプリのプロジェクトフォルダで@<code>{git init}を実行した。

ターミナルに表示された文字。

//quote{
Initialized empty Git repository in /Users/sho/MyTodo/.git/
//}

「空のGitリポジトリが初期化されました」。たった一行のメッセージが、翔にとっては新しい章の始まりだった。

@<code>{git add .}、@<code>{git commit -m "最初のコミット"}、@<code>{git push -u origin main}。

コマンドを一つずつ打ち込むたびに、翔は自分が「エンジニアの道具」を一つずつ手に入れている実感を覚えた。Xcode、SwiftUI、MapKit、そしてGit。デザイナーがIllustrator、Photoshop、InDesign、Bridgeと道具を揃えていくのと同じように。

帰り際、村田さんが言った。

「GitHubのプロフィールにリポジトリが並んでいくと、自分の成長が見える化されるんだよね。一ヶ月後、三ヶ月後に振り返ると、すごく励みになるから」

翔はその言葉を、心の中で反芻した。


== Swiftの深層

十二月も半ばを過ぎ、翔のSwiftUI学習は三つの柱で進んでいた。

一つ目は、Swiftful ThinkingのYouTubeチュートリアル。手を動かしてアプリを作る実践。二つ目は、「The Swift Programming Language」。Swift言語そのものの仕様を理解する座学。三つ目は、「Swift実践入門」。日本語で文法を確認する辞書的な使い方。

三つを並行して進める中で、翔は@<b>{Optional}という概念にぶつかった。

//list[optional_basic][Optionalの基本][swift]{
// 値があるかもしれないし、ないかもしれない
var userName: String? = nil

// nilの可能性があるので、直接使えない
// print(userName.count) // コンパイルエラー！

// if letでアンラップする（安全に取り出す）
if let name = userName {
    print("名前: \(name)")
} else {
    print("名前が設定されていません")
}

// guard letでアンラップする（早期リターン）
func greet(name: String?) {
    guard let name = name else {
        print("名前がありません")
        return
    }
    // ここではnameは必ず値がある
    print("こんにちは、\(name)さん！")
}
//}

@<code>{String?}——型名の後ろにクエスチョンマークが付くと、それは@<b>{Optional型}になる。「値があるかもしれないし、nilかもしれない」という状態を表す。

翔は最初、この概念が理解できなかった。変数には値が入っているか入っていないかの二択で、なぜわざわざ「入っていないかもしれない」を型として表現するのか。

しかし、APIからデータを取得するケースを考えると合点がいった。ユーザーのプロフィール画像のURLを取得する。ユーザーが画像を設定していなければ、URLは存在しない——つまり@<code>{nil}だ。このとき、プロフィール画像のURLの型は@<code>{String?}（Optional<String>）になる。

「値がないかもしれない」を安全に扱うための仕組み。それがOptionalだ。

@<code>{if let}は「値があれば取り出して使う、なければelseに進む」。@<code>{guard let}は「値がなければ早期にreturnして、以降のコードでは値があることを保証する」。

//list[optional_patterns][Optionalの実践パターン][swift]{
struct UserProfile {
    let name: String
    let email: String
    let avatarURL: String?      // 画像は設定されていないかもしれない
    let bio: String?            // 自己紹介も任意
    let websiteURL: String?     // ウェブサイトも任意
}

func displayProfile(_ profile: UserProfile) {
    print("名前: \(profile.name)")
    print("メール: \(profile.email)")

    // Optional Bindingでアンラップ
    if let avatarURL = profile.avatarURL {
        print("アバター: \(avatarURL)")
    }

    // nil合体演算子（??）でデフォルト値を設定
    let bio = profile.bio ?? "自己紹介はまだありません"
    print("自己紹介: \(bio)")

    // Optional Chainingで安全にプロパティにアクセス
    let websiteHost = profile.websiteURL?.components(
        separatedBy: "/"
    ).dropFirst(2).first
    print("ウェブサイト: \(websiteHost ?? "未設定")")
}
//}

@<code>{??}（nil合体演算子）は「Optionalの値がnilだった場合に使うデフォルト値」を指定する。@<code>{?.}（Optional Chaining）は「nilでなければプロパティにアクセスし、nilならnil」を返す。

翔はこれらのパターンをノートに書き出した。デザイナー時代のスケッチブックに、今はSwiftのコードパターンが書かれている。

//note[Optionalが重要な理由]{
SwiftのOptionalは、多くのプログラミング言語に存在する@<b>{null参照の問題}を安全に解決するための仕組みだ。

JavaやJavaScriptでは、nullの変数にアクセスすると実行時にクラッシュする（NullPointerExceptionなど）。Swiftではコンパイル時にOptionalの扱いをチェックするため、@<b>{アプリ実行中にnilによるクラッシュが起きにくい}設計になっている。

初心者にとってOptionalは最初の大きな壁だが、理解すれば「安全なコード」が自然に書けるようになる。SwiftがOptionalを型システムに組み込んでいるのは、開発者を守るための設計思想だ。
//}


== チュートリアルヘル

年が明けた。一月。

翔のSwiftUI学習は四ヶ月目に入っていた。

Swiftful ThinkingのBootcampプレイリストはすべて完走した。Map Appのチュートリアルも完走した。Apple公式のLandmarksチュートリアルは二周した。The Swift Programming Languageの基本文法セクションは一通り読んだ。Swift実践入門も半分まで進んだ。

GitHubのリポジトリには、チュートリアルのプロジェクトが六つ並んでいる。Todoアプリ、地図アプリ、天気予報アプリ、ニュースアプリ、暗号資産追跡アプリ、レシピアプリ。すべてSwiftful Thinkingのチュートリアルを写経したものだ。

翔は、着実に成長している実感があった。

@<code>{VStack}と@<code>{HStack}を見れば瞬時にレイアウトが頭に浮かぶ。@<code>{@State}と@<code>{@Binding}の使い分けは体に染みついている。@<code>{List}と@<code>{NavigationStack}でデータ一覧と画面遷移を実装できる。MVVMの設計パターンも理解した。Gitでバージョン管理もしている。

しかし、ある夜。

翔はXcodeで「New Project」を選択し、空のSwiftUIプロジェクトを作成した。Product Nameに「MyOriginalApp」と入力する。

画面にはおなじみの@<code>{ContentView.swift}が表示される。

//list[empty_contentview][何も書かれていないContentView][swift]{
import SwiftUI

struct ContentView: View {
    var body: some View {
        VStack {
            Image(systemName: "globe")
                .imageScale(.large)
                .foregroundStyle(.tint)
            Text("Hello, World!")
        }
        .padding()
    }
}
//}

翔はキーボードに手を置いた。

何を書けばいい？

チュートリアルのときは、Nickが「ここに@<code>{List}を追加しましょう」と言ってくれた。Apple公式チュートリアルは、次に書くべきコードがステップバイステップで提示されていた。しかし今、画面には何のガイドもない。白紙のXcodeプロジェクト。「Hello, World!」だけが、翔を見つめ返している。

三十分が経った。翔が書いたのは、@<code>{Text("Hello, World!")}を削除して@<code>{Text("")}にしただけだった。

一時間。画面は変わらない。

翔は席を立ち、コーヒーを淹れた。マグカップを両手で包みながら、MacBook Airの画面を遠くから見つめた。

自分は四ヶ月も勉強してきた。チュートリアルは何本も完走した。GitHubにはリポジトリが六つある。しかし、それらはすべて@<b>{誰かが設計したアプリの写経}だ。データモデルも、UIの構成も、画面遷移のフローも、すべて誰かが決めたものをなぞっただけ。

ゼロから設計する力が、翔にはなかった。

翌日、翔はXで何気なく検索した。「チュートリアル　作れない」。

そこで、ある言葉に出会った。

@<b>{チュートリアルヘル}（Tutorial Hell）。

プログラミング学習者の間で広く知られた現象だった。チュートリアルを何本やっても、自分でゼロからアプリを作れるようにならない状態。チュートリアルの中では理解できるのに、チュートリアルの外に出た途端、何も書けなくなる。

翔はXの検索結果を読み漁った。同じ苦しみを語る人が、驚くほど多かった。

//quote{
チュートリアル三十本やったけど、自分のアプリは一つも完成していない。写経と理解の間に、見えない壁がある。
//}

//quote{
チュートリアルヘルを抜け出すには、「完璧を目指さず、不完全でもいいから自分のアプリを作り始めること」が唯一の方法だと思う。
//}

写経と理解の間の、見えない壁。

翔はその言葉を噛みしめた。デザインの世界にも同じ構造がある。デザインの教科書を読み、他人の作品を模写し、ソフトの操作を覚える。しかし、白紙のアートボードにゼロからデザインを生み出す力は、模写だけでは身につかない。自分で考え、自分で判断し、自分で形にする経験が必要だ。

翔はコーヒーを飲み干し、Xcodeの前に座り直した。


== 白紙のXcodeプロジェクト

チュートリアルヘルを自覚した翔は、戦略を変えることにした。

チュートリアルをやめる。自分のアプリを作る。

しかし、「何を作るか」を決めるのが、想像以上に難しかった。

中野と美咲はSNSアプリを作った。村田さんはタスク管理から瞑想タイマーまで十二本のアプリをリリースしている。CA.swiftのエンジニアたちは、大規模サービスの技術基盤を構築している。

翔に作れるものは何だ？

Todoアプリ——もう作った。地図アプリ——チュートリアルの写経だ。天気予報アプリ——同じく写経。

翔は第一章で作ったTodoアプリの画面をシミュレータに表示した。自分が一から設計した、唯一のオリジナルアプリ。シンプルだが、CRUDは動く。UIもデザイナーとして最低限の品質はある。

「これを、App Storeにリリースしよう」

翔は声に出して言った。

App Store。世界中のiPhoneユーザーがアプリをダウンロードする場所。そこに、自分のアプリを並べる。

もちろん、今のTodoアプリには課題が山積みだ。データの永続化がない。アプリを閉じるとデータが消える。カテゴリ分けもない。リマインダー機能もない。デザインも改善の余地がある。

しかし、完璧を目指していたら永遠にリリースできない。チュートリアルヘルから抜け出すには、不完全でもいいから「自分で作って、世に出す」しかない。

翔はXcodeのMyTodoプロジェクトを開き直した。白紙のプロジェクトではなく、すでに動いているプロジェクトだ。ここに機能を追加し、改善し、リリースする。

しかし、翔のコードの前に立ちはだかる壁があった。

志村さんが以前リプライで言っていた「データの永続化」。アプリを閉じてもデータが残る仕組み。翔はSwiftful Thinkingで@<code>{UserDefaults}と@<code>{SwiftData}の動画を見たが、自分のTodoアプリにどう組み込むかがわからない。チュートリアルでは「こう書いてください」と言われた通りに書けば動いた。しかし、自分のコードのどこに、どう組み込めばいいのか。

設計の力が足りない。

翔はXcodeの画面を見つめた。白紙ではないが、次の一行が書けない。

「……誰かに聞けたらいいのに」

翔は呟いた。志村さんはXでアドバイスをくれるが、コードの詳細まで見てもらうのは限界がある。村田さんはもくもく会で相談に乗ってくれるが、月に一度しか会えない。

その夜、翔はXのタイムラインを眺めていた。とあるツイートが目に入った。

//quote{
AIコードエディタ「Cursor」のイベントに行ってきた。すごい時代になったな。AIがペアプログラミングの相棒になる日が来るとは。
//}

AIコードエディタ。翔はそのツイートをブックマークした。

午前一時。MacBook Airの画面には、Todoアプリのコードが表示されている。翔はまだ「次の一行」を見つけられていない。しかし、チュートリアルヘルの自覚は、翔にとって大きな一歩だった。

問題が見えている。問題が見えているなら、解き方も見つかるはずだ。

デザインの世界で、翔はそうやって壁を乗り越えてきた。クライアントの曖昧な要望を「問題」として定義し、視覚的な「解決策」に変換する。それがグラフィックデザイナーの仕事だ。

プログラミングでも、きっと同じだ。

翔はターミナルを開いた。

//list[git_commit_chapter2_end][その日最後のコミット][shell]{
git add .
git commit -m "チュートリアルヘルを抜け出すために：リリースに向けた課題整理"
git push origin main
//}

GitHubのリポジトリに、翔の決意がコミットされた。

まだ何もリリースしていない。まだチュートリアルヘルの只中にいる。しかし、翔のGitHubには八つのリポジトリが並び、Xのタイムラインには四ヶ月分の学習記録が刻まれ、Connpassには参加イベントの履歴が残っている。

積み重ねてきたものは、消えない。コードと同じだ。@<code>{git log}を叩けば、すべての履歴が表示される。

翔のMacBook Airが、スリープに入る前の最後の光を放った。画面が暗くなる直前、翔はブックマークしたツイートをもう一度見た。

「AIコードエディタ、Cursor——」

その名前を、スマートフォンのメモ帳に書き留めた。Swift、SwiftUI、Xcode、MapKit、Git、GitHub。そしてCursor。

翔の道具箱に、新しい名前が加わろうとしていた。
