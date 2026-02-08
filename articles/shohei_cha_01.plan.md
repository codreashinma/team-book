---
name: iOS小説第1章執筆
overview: グラフィックデザイナーがiOSアプリ開発と出会い、SwiftUIを学び始めるまでの第1章（約20,000文字）をRe:VIEW形式で執筆する。実際のSwiftUIコードを物語に織り込み、読みながら技術も学べる構成にする。
todos:
  - id: write-chapter1
    content: 第1章（約20,000文字）をRe:VIEW形式で shohei_cha_01.re に執筆する。10セクション構成、SwiftUIコード例を含むライトノベル×ビジネス小説スタイル
    status: completed
---

# iOS小説 第1章 Re:VIEW形式執筆プラン

## キャラクター設定

- **主人公**: 水野 純一（みずの じゅんいち）28歳男性。グラフィックデザイン制作会社のアシスタントデザイナー3年目。壁にはNeville Brodyのポスター
- **エンジニア1**: 中野 健太（なかの けんた）タクシー配車アプリ会社のモバイルエンジニア。言語交換ミートアップで出会う
- **エンジニア2**: 藤原 美咲（ふじわら みさき）国内有数のモバイルゲーム会社のエンジニア
- **Xのアドバイザー**: 志村さん（清水さんの仮名）
- **SNSアプリ名**: 「Ignore」（そのまま使用）

## 第1章の構成（10セクション、各約2,000文字）

### セクション1: 午前一時の独白（~2,000字）

- ユーザー提供の冒頭シーンをベースに展開
- 純一の日常の閉塞感、デザイン会社での歯車感を描写
- MacBook Air、散乱するデザイン雑誌、深夜の孤独
- 「何かゼロから作りたい」という渇望

### セクション2: 言語交換ミートアップでの出会い（~2,000字）

- 数週間前の回想：六本木のバーでの言語交換イベント
- 中野健太との出会い、個人開発アプリ事業への誘い
- デザイナーとして声をかけられた嬉しさと不安

### セクション3: コワーキングスペースでの衝撃（~2,000字）

- もくもく会参加、藤原美咲との出会い
- 2人が1週間でSNSアプリ「Ignore」を完成させていた事実
- 純一はアイコン制作しかできず、無力感と同時に強烈な憧れ
- Xcode、Swift、SwiftUIという単語を初めて聞く

### セクション4: 決意とXcodeとの最初の格闘（~2,000字）

- 深夜、MacでXcodeをダウンロード（容量の大きさに驚く）
- Xcodeの起動、初めてのプロジェクト作成
- "Hello, World!"の表示 → SwiftUIの `Text("Hello, World!")` コード
- **コード例**: 最初のContentView.swift
```swift
struct ContentView: View {
    var body: some View {
        Text("Hello, World!")
    }
}
```


### セクション5: Apple公式チュートリアル「Landmarks」（~2,000字）

- Apple Developer公式のSwiftUIチュートリアルに挑戦
- Landmarksアプリの構造を学ぶ
- VStack, HStack, Image, Textの基本レイアウト
- **コード例**: Landmarks風のレイアウトコード
```swift
VStack {
    Image("landmark")
        .clipShape(Circle())
    Text("ランドマーク名")
        .font(.title)
    HStack {
        Text("東京都")
        Spacer()
        Text("日本")
    }
}
```


### セクション6: 最初のバグとの遭遇（~2,000字）

- チュートリアル通りにやっているのにビルドエラー
- エラーメッセージが英語で理解できない
- 何時間もGoogle検索するが解決せず
- プログラミングの壁を実感する絶望感の描写

### セクション7: Xでの救い — 志村さんとの出会い（~2,000字）

- 藁にもすがる思いでXに投稿
- 志村さんからのリプライ：具体的なアドバイス
- **技術解説**: @Stateプロパティラッパーの概念説明をストーリーに織り込む
- バグが解決した瞬間の達成感
```swift
@State private var isToggled = false
// Stateを付けることで値の変更がUIに反映される
```


### セクション8: Swiftful Thinkingとの出会い（~2,000字）

- 志村さんに勧められてYouTubeチャンネル「Swiftful Thinking」を発見
- 英語だが、コードを見ながら真似するスタイルが合う
- SwiftUIの基本コンポーネントを体系的に学び始める
- **コード例**: NavigationView, List, Buttonの基本
```swift
NavigationView {
    List {
        Text("Item 1")
        Text("Item 2")
    }
    .navigationTitle("My List")
}
```


### セクション9: Todoアプリ制作 — 初めての「自分のアプリ」（~2,000字）

- 学んだ知識を総動員してTodoアプリを作り始める
- データモデルの設計、CRUD操作
- **コード例**: Todoのデータモデルと画面
```swift
struct TodoItem: Identifiable {
    let id = UUID()
    var title: String
    var isCompleted: Bool
}

struct TodoListView: View {
    @State private var todos: [TodoItem] = []
    @State private var newTodoTitle = ""
    
    var body: some View {
        NavigationView {
            List {
                ForEach(todos) { todo in
                    HStack {
                        Image(systemName: todo.isCompleted 
                            ? "checkmark.circle.fill" 
                            : "circle")
                        Text(todo.title)
                    }
                }
            }
            .navigationTitle("My Todo")
        }
    }
}
```


### セクション10: シミュレータに映る自分の作品（~2,000字）

- Todoアプリがシミュレータで動く瞬間
- デザイナーとしての目で「UIをもっと良くしたい」と思う
- グラフィックデザインの経験がここで活きる予感
- 次章への伏線：Swiftful Thinkingで地図アプリを作る決意
- 章の締め：「午前一時。水野純一のMacBook Airは、もう冷たい光ではなかった」

## ファイル構成

- `shohei_cha_01.re` — 第1章本文（Re:VIEW形式）

## Re:VIEW記法の主要要素

- `= 章タイトル` (章見出し)
- `== セクション見出し`
- `//list[id][キャプション][lang]{ ... //}` (コードブロック)
- `@<code>{インラインコード}`
- `@<b>{太字}`, `@<i>{斜体}`
- `//note[タイトル]{ ... //}` (技術解説コラム)
- `//quote{ ... //}` (引用)
