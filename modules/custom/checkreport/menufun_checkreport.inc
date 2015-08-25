<?php

/**
 * report content
 * @return string
 *  HTML for the page
 */
function menufun_checkreport_content($sample_id = NULL) {
  global $user;
  $arr_pie = array();
  $result = db_query("SELECT tax_name,abundance FROM {checkreport_result} WHERE uid=:uid AND sample_id=:sample_id", array(':uid' => $user->uid, ':sample_id' => $sample_id));
  foreach($result as $row){
    array_push($arr_pie, array($row->tax_name,$row->abundance));
  }
  if(count($arr_pie)){
    $intr_txt_content = "
      <br>
      <h4 class=\"ui horizontal divider header\"><i class=\"tag icon\"></i>患病风险分析</h4>
     <div class=\"ui padded raised segment\">
     <p style=\" text-indent:2em;\">口腔菌群与很多疾病关系密切[1-2]：口腔溃疡，牙周病，牙髓病，磨损，上颌前突，青少年牙周炎，舌病，唇病，龋齿，唇裂，四环素牙，单纯性牙周炎，口腔念珠菌病， 腭裂等都属于常见的口腔疾病，这些常见的口腔疾病发病率非常高，却往往容易被人们所忽视。
     </p>
     <p style=\" text-indent:2em;\">口腔中存在700多种细菌，菌群失调会引起许多种口腔疾病，而牙龈内的神经却不怎么敏感，常常牙周已经病了却还没把疼痛信号传递给大脑。据《第三次全国口腔健康流行病学调查报告》显示，我国全民口腔患病率高达97.6%。
     感觉口腔出问题的时候，往往已是“中晚期”。
     </p>
     <p style=\" text-indent:2em;\">口腔里既有好益生菌，也有有害菌，当有害菌增多，口腔内微妙的生态平衡被打破的时候，细菌就会沿着缝隙深入破坏，若没干预，会一直侵蚀到牙槽骨,当发展为牙周炎时，缺失的牙槽骨已无处可寻，严重的只能通过手术修复了。近年来的研究显示，口腔疾病与心脏病和中风的发生有着密切关系—牙病也会导致心脑血管病，已成为医学界共识。口腔病原菌还会导致呼吸系统疾病、消化系统疾病、糖尿病和老年痴呆等。
     </p>
     <p style=\" text-indent:2em;\">保持口腔健康，早期预防是关键！通过定期口腔微生态健康体检可以对口腔菌群健康进行监测，并对常见口腔疾病龋齿、牙周炎、口腔癌及口臭发生风险进行评估，从而提供预防和保健建议。
     </p>
      <div class=\"ui olive inverted segment\">
        <div class=\"ui middle header\"><i class=\"doctor icon\"></i>口气</div>
        <div class=\"ui divider\"></div>
        <div class=\"ui green inverted left floated segment\">
          <h2 class=\"ui inverted header\">
          34%
          <div class=\"sub header\">患病概率</div>
          </h2>
        </div>
        <p style=\" text-indent:2em;\">
        口气（俗称口臭）严重影响人们的社会交往和心理健康，WHO已将口气作为一种疾病来进行报道。调查显示，中国口气患病率为27.5%。全球约有10%~65%的人曾患有口气。据统计，80%~90% 的口气是来源于口腔。深龋窝洞内、不良修复体悬突下常残存食物残渣和菌斑，细菌经过发酵分解，产生臭味。牙髓坏死或化脓性牙髓炎，未经治疗也可发出臭味；牙周病患者常伴有大量的牙石、菌斑，牙周袋内细菌发酵产生硫化氢、吲哚和氨类，因而产生臭味。另外，牙周脓肿和牙周袋溢脓，多为金黄色葡萄球菌合并牙周致病菌感染，也会发出臭味。口臭成因很多，口腔菌群失衡是关键。
        </p>
      </div>
      <div class=\"ui olive inverted segment\">
        <div class=\"ui middle header\"><i class=\"doctor icon\"></i>龋齿</div>
        <div class=\"ui divider\"></div>
        <div class=\"ui green inverted left floated segment\">
          <h2 class=\"ui inverted header\">
          5%
          <div class=\"sub header\">患病概率</div>
          </h2>
        </div>
        <p style=\" text-indent:2em;\">
        全世界60~90%的学龄儿童和近100%的成年人有龋齿，这往往会带来疼痛和不适。根据第三次全国口腔健康流行病学调查结果显示，我国中老年人龋齿患病率分别高达88.1%和98.4%。我国的5岁组的儿童患龋齿的概率高达50%~66%，也就是平均两个小孩就有一个小孩有龋齿。每个人的口腔里都有诸如变形链球菌、乳酸杆菌、放线菌等这些致龋细菌，只是相互之间的比例、数量人与人之间不同，龋病发生的必要条件就是这些致龋细菌的存在。预防龋齿，监测致龋细菌是关键。
        </p>
      </div>
    </div>
    ";
    $chart = array(
      'id' => 'visualization',
      'type' => 'PieBar',
      'rows' => $arr_pie,
    );

//条状图部分
    $color = array('blue', 'red', 'orange', 'green', 'purple', 'lightblue', 'palevioletred', 'orangered', 'mediumpurple', 'pink', 'yellow', 'olive', 'mediumorchid');
    $ref_abundance = array(
      array(0.0261, 0.199, 0.061),
      array(0.050, 0.309, 0.144),
      array(0.012, 0.084, 0.025),
      array(0.041, 0.202, 0.101),
      array(0.025, 0.157, 0.049),
      );
    $pie_bar_content = "
    <div style=\"float:right;width:500px\">
      <div class=\"ui three item  menu\">
        <div class=\"item\" >细菌名称</div>
        <div class=\"item\">您的菌群</div>
        <div class=\"item\">参考区间（平均值）</div>
      </div>
    ";
    for($row=0; $row < count($arr_pie); $row++){
      $pie_bar_content .= "
      <div class=\"ui small modal ".$arr_pie[$row][0]."\">
        <i class=\"close icon\"></i>
        <div class=\"header\">".$arr_pie[$row][0]."</div>
        <div class=\"description\">
          <div class=\"ui header\">背景知识</div>
          <p>
          介绍该属背景知识
          </p>
          <div class=\"ui header\">参考文献</div>
          <p>
         [1] Wade W G. The oral microbiome in health and disease. Pharmacological Research, 2013, 69(1): 137-143.
         <br>
         [2] Zarco M F, et al. The oral microbiome in health and disease and the potential impact on personalized dental medicine. Oral diseases, 2012, 18(2): 109-120.
          </p>
        </div>
      </div>
      <div class=\"ui ".$color[$row]." inverted three item menu\">
        <a class=\"item\" onclick=jQuery(\".ui.modal.".$arr_pie[$row][0]."\").modal(\"show\")>".$arr_pie[$row][0]."</a>";
//指标高低判断
      if($arr_pie[$row][1] < $ref_abundance[$row][0]){
        $pie_bar_content .= "
          <a class=\"item\">".$arr_pie[$row][1]."<i class=\"long arrow down icon\"></i></a>";
      }elseif($arr_pie[$row][1] > $ref_abundance[$row][1]){
        $pie_bar_content .= "
          <a class=\"item\">".$arr_pie[$row][1]."<i class=\"long arrow up icon\"></i></a>";
      }else{
        $pie_bar_content .= "
          <a class=\"item\">".$arr_pie[$row][1]."</a>";
      }
      $pie_bar_content .= "
        <a class=\"item\">".$ref_abundance[$row][0]."~".$ref_abundance[$row][1]."(".$ref_abundance[$row][2].")</a>
      </div>";
    }
    $pie_bar_content .= "</div>";
    $pie_content = d3_draw($chart).$pie_bar_content;
    $pie_txt_content = "
      <h4 class=\"ui horizontal divider header\"><i class=\"pie chart icon\"></i>口腔菌组成调查结果</h4>
    ";

    $dashboard = array(
      'id' => 'visu_dashboard',
      'type' => 'dashboard',
    );
    $dashboard_content = d3_draw($dashboard);
    $dash_txt_content = "
      <h4 class=\"ui horizontal divider header\"><i class=\"pie chart icon\"></i>家庭成员口腔菌对比</h4>
    ";
    $line = array(
        'id' => 'visualization2',
        'type' => 'LineGraph',
        'legend' => array(
          'Development',
          'QA',
          'Strategy',
          'Design',
        ),
        'rows' => array( array('1st Quarter 2011',10,20,26,35),
          array('2nd Quarter 2011',20,26,27,37),
          array('3rd Quarter 2011',10,50,28,50),
          array('4th Quarter 2011',15,76,49,51),
          array('1st Quarter 2012',20,100,50,52),
        ),
    );
    $line_txt_content = "
      <h4 class=\"ui horizontal divider header\"><i class=\"pie chart icon\"></i>历次检测口腔菌对比</h4>
    ";
    $line_content = d3_draw($line);
  $content = "$intr_txt_content<br>$pie_txt_content<br>$pie_content<br>$dash_txt_content<br>$dashboard_content<br>$line_txt_content<br>$line_content";
  }else{
    $content = "您的报告还在加紧准备中，请耐心等待";
  }
  return $content;
}
