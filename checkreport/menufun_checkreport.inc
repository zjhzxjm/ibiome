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
    $chart = array(
      'id' => 'visualization',
      'type' => 'PieChart',
      'rows' => $arr_pie, 
    );
    $pie_content = d3_draw($chart);
    $txt_content = "
      <h3>一、物种丰度分析</h3>
      <br>
      <p><em>分</em>别在门、纲、目、科、属分类等级对各个样品做物种profiling相应的柱状图。</p> 
    ";
    $content = "$txt_content<br>$pie_content";
  }else{
    $content = "您的报告还在加紧准备中，请耐心等待";
  }
  return $content;
}
