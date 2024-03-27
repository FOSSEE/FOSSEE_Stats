<?php
function all_time_fossee_stats_json() {
   $activity = arg(3);
   //var_dump($activity);die;
   //$page_output =  "";
   //$page_output .= t("Fetched at ") . time();
   if($activity == 'TBC'){
   $query = db_select('foss_type');
       $query->fields('foss_type');
        $query->condition('tbc', 1);
        $result = $query->execute();
        $book_data = array();
        $activity_data = array();
        while($foss_detail = $result->fetchObject()){
         //$json_output = '[ " ' . $foss_type . ' :"';
         //var_dump($foss_detail->foss_name);die;
            $foss_type = $foss_detail->foss_name;
      db_set_active($foss_type);         
if ($foss_detail->foss_name != 'Scilab' || $foss_detail->foss_name != 'R') {  
   db_set_active($foss_type);
   $query2 = db_query("SELECT COUNT( pe.book ) as book_count, FROM_UNIXTIME(po.completion_date, '%Y') as year_completion FROM textbook_companion_preference pe LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id WHERE po.proposal_status =3 AND pe.approval_status =1 and from_unixtime(po.completion_date, '%Y') >= '2019' group by from_unixtime(po.completion_date, '%Y')");
   while($book_count_data = $query2->fetchAll()){
      //var_dump($book_count_data);die;
      $book_data[$foss_type] = array($book_count_data);
      //var_dump($book_data);die;
  }
  //var_dump($book_data);die;
 }
 else if ($foss_detail->foss_name == 'Scilab' || $foss_detail->foss_name == 'R') {  
   db_set_active($foss_type);
   $query3 = db_query("SELECT count(DISTINCT pe.id) as book_count, FROM_UNIXTIME(po.completion_date, '%Y') as year_completion
      FROM textbook_companion_preference pe
      LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id
      LEFT JOIN textbook_companion_book_main_subcategories tcbm ON pe.id = tcbm.pref_id
      LEFT JOIN list_of_category loc ON tcbm.main_category = loc.category_id
      WHERE po.proposal_status = 3 AND pe.approval_status = 1 AND pe.category>0
      AND pe.id = tcbm.pref_id and from_unixtime(po.completion_date, '%Y') >= '2019' group by from_unixtime(po.completion_date, '%Y')");
   while($book_count_data = $query3->fetchAll()){
      //var_dump($book_count_data);die;
      $book_data[$foss_type] .= array($book_count_data);
      //var_dump($book_data);die;
  }
  //var_dump($book_data);die;
 }
 } //$book_data[$foss_type] .= $book_data; 
 $book_data['fetched at'] .= time();
 drupal_json_output($book_data);
}
else if($activity == 'LM'){
$query = db_select('foss_type');
       $query->fields('foss_type');
        $query->condition('lab_migration', 1);
        $result = $query->execute();
        $book_data = array();
        while($foss_detail = $result->fetchObject()){
         //$json_output = '[ " ' . $foss_type . ' :"';
         //var_dump($foss_detail->foss_name);die;
            $foss_type = $foss_detail->foss_name;
      db_set_active($foss_type);         
   $query2 = db_query("SELECT COUNT(id) as lab_count, from_unixtime(approval_date, '%Y') as year_completion FROM lab_migration_proposal WHERE approval_status = '3' and from_unixtime(approval_date, '%Y') >= '2019' GROUP BY from_unixtime(approval_date, '%Y') order by approval_date ASC");
   while($book_count_data = $query2->fetchAll()){
      //var_dump($book_count_data);die;
      $book_data[$foss_type] = array($book_count_data);
      //var_dump($book_data);die;
  }
  //var_dump($book_data);die;
 } 
 $book_data['fetched at'] .= time(); 
drupal_json_output($book_data);
}
else if($activity == 'Niche-activities'){
   $query = db_select('foss_type');
   $query->fields('foss_type');
        $query->condition('niche_activities', 1);
        $result = $query->execute();     //var_dump($result->fetchObject());die;
        while($foss_detail = $result->fetchObject()) {
               $foss_type = $foss_detail->foss_name;

            //var_dump($table_name);
            $query = db_query("SELECT * FROM foss_niche_activites a WHERE a.foss_id=:foss_id and is_active=1", array(
               ":foss_id" => $foss_detail->id
            ));
            while($activity_detail = $query->fetchObject()){
               //var_dump($activity_detail);die;
               $table_name = $activity_detail->activity_table_details;
         
          db_set_active($foss_type);
            $query2 = db_query("SELECT COUNT(project_title) as projects_completed_count, from_unixtime(actual_completion_date, '%Y') as year_completion FROM " . $table_name . " WHERE approval_status = 3 AND from_unixtime(actual_completion_date, '%Y') >= '2019' GROUP BY from_unixtime(actual_completion_date, '%Y') order by actual_completion_date ASC"); 
               while($book_count_data = $query2->fetchAll()){
                  $activity_data[$foss_type . ' ' . $activity_detail->activity_name] = $book_count_data;
               }
                        
         //$activity_data[$activity_detail->activity_name] =array($book_count_data);
         db_set_active();     
}
         
         }
         $activity_data['fetched at'] .=   time();
$book_data  = array($activity_data);
 drupal_json_output($book_data);
 //exit;
         }
//return $page_output;

}
function fossee_stats_json() {
   $activity = arg(3);
   $year_of_completion = arg(2);
   $quarter = arg(4);
   switch ($quarter) {
      case 'Q1':
         $quarter_start_month = "01";
         $quarter_end_month = "03";
         break;
      case 'Q2':
         $quarter_start_month = "04";
         $quarter_end_month = "06";
         break;
      case 'Q3':
         $quarter_start_month = "07";
         $quarter_end_month = "09";
         break;
      case 'Q4':
         $quarter_start_month = "10";
         $quarter_end_month = "12";
         break;
      
      default:
         // code...
         break;
   }
   //var_dump($activity);die;
   if($activity == 'TBC'){
   $query = db_select('foss_type');
       $query->fields('foss_type');
        $query->condition('tbc', 1);
        $result = $query->execute();
        $book_data = array();
        $activity_data = array();
        while($foss_detail = $result->fetchObject()){
         //$json_output = '[ " ' . $foss_type . ' :"';
         //var_dump($foss_detail->foss_name);die;
            $foss_type = $foss_detail->foss_name;
      db_set_active($foss_type);         
if ($foss_detail->foss_name != 'Scilab' || $foss_detail->foss_name != 'R') {  
   db_set_active($foss_type);
   $query2 = db_query("SELECT COUNT( pe.book ) as book_count, FROM_UNIXTIME(po.completion_date, '%m') as month_of_year FROM textbook_companion_preference pe LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id WHERE po.proposal_status =3 AND pe.approval_status =1 and from_unixtime(po.completion_date, '%Y') = " . $year_of_completion . " and from_unixtime(po.completion_date, '%m') between " . $quarter_start_month . " and " . $quarter_end_month . " group by from_unixtime(po.completion_date, '%m') order by po.completion_date ASC");
   while($book_count_data = $query2->fetchAll()){
      //var_dump($book_count_data);die;
      $book_data[$foss_type] = array($book_count_data);
      //var_dump($book_data);die;
  }
  //var_dump($book_data);die;
 }
 else if ($foss_detail->foss_name == 'Scilab' || $foss_detail->foss_name == 'R') {  
   db_set_active($foss_type);
   $query3 = db_query("SELECT count(DISTINCT pe.id) as book_count, FROM_UNIXTIME(po.completion_date, '%m') as month_of_year
      FROM textbook_companion_preference pe
      LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id
      LEFT JOIN textbook_companion_book_main_subcategories tcbm ON pe.id = tcbm.pref_id
      LEFT JOIN list_of_category loc ON tcbm.main_category = loc.category_id
      WHERE po.proposal_status = 3 AND pe.approval_status = 1 AND pe.category>0
      AND pe.id = tcbm.pref_id and from_unixtime(po.completion_date, '%Y') =" . $year_of_completion . " and from_unixtime(po.completion_date, '%m') between " . $quarter_start_month . " and " . $quarter_end_month . " group by from_unixtime(po.completion_date, '%m') order by po.completion_date ASC");
   while($book_count_data = $query3->fetchAll()){
      //var_dump($book_count_data);die;
      $book_data[$foss_type] .= array($book_count_data);
      //var_dump($book_data);die;
  }
  //var_dump($book_data);die;
 }
 } //$book_data[$foss_type] .= $book_data; 
 $book_data['fetched at'] .= time(); 
 drupal_json_output($book_data);
}
else if($activity == 'LM'){
$query = db_select('foss_type');
       $query->fields('foss_type');
        $query->condition('lab_migration', 1);
        $result = $query->execute();
        $book_data = array();
        while($foss_detail = $result->fetchObject()){
         //$json_output = '[ " ' . $foss_type . ' :"';
         //var_dump($foss_detail->foss_name);die;
            $foss_type = $foss_detail->foss_name;
      db_set_active($foss_type);         
   $query2 = db_query("SELECT COUNT(id) as lab_count, from_unixtime(approval_date, '%m') as month_of_year FROM lab_migration_proposal WHERE approval_status = '3' and from_unixtime(approval_date, '%Y') =" . $year_of_completion . " and from_unixtime(approval_date, '%m') between " . $quarter_start_month . " and " . $quarter_end_month . " GROUP BY from_unixtime(approval_date, '%m') order by approval_date ASC");
   while($book_count_data = $query2->fetchAll()){
      //var_dump($book_count_data);die;
      $book_data[$foss_type] = array($book_count_data);
      //var_dump($book_data);die;
  }
  //var_dump($book_data);die;
 } //$book_data[$foss_type] .= $book_data; 
 $book_data['fetched at'] .= time(); 
drupal_json_output($book_data);
}
else if($activity == 'Niche-activities'){
   $query = db_select('foss_type');
   $query->fields('foss_type');
        $query->condition('niche_activities', 1);
        $result = $query->execute();     //var_dump($result->fetchObject());die;
        while($foss_detail = $result->fetchObject()) {
               $foss_type = $foss_detail->foss_name;

            //var_dump($table_name);
            $query = db_query("SELECT * FROM foss_niche_activites a WHERE a.foss_id=:foss_id and is_active=1", array(
               ":foss_id" => $foss_detail->id
            ));
            while($activity_detail = $query->fetchObject()){
               //var_dump($activity_detail);die;
               $table_name = $activity_detail->activity_table_details;
         
          db_set_active($foss_type);
            $query2 = db_query("SELECT COUNT(project_title) as projects_completed_count, from_unixtime(actual_completion_date, '%m') as month_of_year FROM " . $table_name . " WHERE approval_status = 3 AND from_unixtime(actual_completion_date, '%Y') = " . $year_of_completion . " and from_unixtime(actual_completion_date, '%m') between " . $quarter_start_month . " and " . $quarter_end_month . " GROUP BY from_unixtime(actual_completion_date, '%m') order by actual_completion_date ASC"); 
               while($book_count_data = $query2->fetchAll()){
                  $activity_data[$foss_type . ' ' . $activity_detail->activity_name] = $book_count_data;
               }
                        
         //$activity_data[$activity_detail->activity_name] =array($book_count_data);
         db_set_active();     
}
         
         }
        $activity_data['fetched at'] .=   time(); 
$book_data  = array($activity_data);
 drupal_json_output($book_data);
 //exit;
         }
return $page_output;

}
