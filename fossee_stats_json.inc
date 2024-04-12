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
        $state_data = array();
        while($foss_detail = $result->fetchObject()){
         //$json_output = '[ " ' . $foss_type . ' :"';
         //var_dump($foss_detail->foss_name);die;
            $foss_type = $foss_detail->foss_name;
         
if ($foss_detail->foss_name != 'Scilab' || $foss_detail->foss_name != 'R') {  
  $state_query = db_query("SELECT * FROM states_lgd_code");
while($state_result = $state_query->fetchObject()){
   db_set_active($foss_type);
   $query2 = db_query("SELECT COUNT( pe.book ) as book_count, FROM_UNIXTIME(po.completion_date, '%Y') as year_completion, state, city FROM textbook_companion_preference pe LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id WHERE po.proposal_status =3 AND pe.approval_status =1 and from_unixtime(po.completion_date, '%Y-%m-%d') between '2019-01-01' and '2024-03-31' and state not like '' and state not like 0 and city not like ''  and city not like 0 and state =:state  group by state,city, year_completion order by po.completion_date ASC", array(":state"=> $state_result->state_name));
   while($book_count_data = $query2->fetchObject()){
      //var_dump($book_count_data);die;
      $book_data[$book_count_data->state][$state_result->state_lgd_code][$book_count_data->city][$foss_type][] = array(
         "count" => $book_count_data->book_count,
         "year_of_completion" => $book_count_data->year_completion
      );
      //var_dump($book_data);die;
  }
}
db_set_active();
 }
 else if ($foss_detail->foss_name == 'Scilab' || $foss_detail->foss_name == 'R') {  
  $state_query = db_query("SELECT * FROM states_lgd_code");
while($state_result = $state_query->fetchObject()){
   db_set_active($foss_type);
   $query3 = db_query("SELECT count(DISTINCT pe.id) as book_count, FROM_UNIXTIME(po.completion_date, '%Y') as year_completion, state, city
      FROM textbook_companion_preference pe
      LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id
      LEFT JOIN textbook_companion_book_main_subcategories tcbm ON pe.id = tcbm.pref_id
      LEFT JOIN list_of_category loc ON tcbm.main_category = loc.category_id
      WHERE po.proposal_status = 3 AND pe.approval_status = 1 AND pe.category>0 and state not like '' and state not like 0 and city not like ''  and city not like 0 and state =:state
      AND pe.id = tcbm.pref_id and from_unixtime(po.completion_date, '%Y-%m-%d') between '2019-01-01' and '2024-03-31' group by state,city, year_completion order by po.completion_date ASC", array(":state"=> $state_result->state_name));
   while($book_count_data = $query3->fetchObject()){
      //var_dump($book_count_data);die;
      $book_data[$book_count_data->state][$state_result->state_lgd_code][$book_count_data->city][$foss_type][] .= array(
         "count" => $book_count_data->book_count,
         "year_of_completion" => $book_count_data->year_completion)
      ;
      //var_dump($book_data);die;
  }
  //var_dump($book_data);die;

}
db_set_active();
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
  $state_query = db_query("SELECT * FROM states_lgd_code");
while($state_result = $state_query->fetchObject()){
      db_set_active($foss_type);         
   $query2 = db_query("SELECT COUNT(id) as lab_count, from_unixtime(approval_date, '%Y') as year_completion,state, city FROM lab_migration_proposal WHERE approval_status = '3'  and state not like '' and state not like 0 and city not like ''  and city not like 0 and state =:state and from_unixtime(approval_date, '%Y-%m-%d') between '2019-01-01' and '2024-03-31' GROUP BY state,city, year_completion order by state ASC", array(":state" => $state_result->state_name));
   while($book_count_data = $query2->fetchObject()){
      //var_dump($book_count_data);die;
      $book_data[$book_count_data->state][$state_result->state_lgd_code][$book_count_data->city][$foss_type][] = array(
         "count" => $book_count_data->lab_count,
         "year_of_completion" => $book_count_data->year_completion
      );
      //var_dump($book_data);die;
  }
}
db_set_active();
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
            $query = db_query("SELECT * FROM foss_niche_activites a WHERE a.foss_id=:foss_id and is_active=1", array(
               ":foss_id" => $foss_detail->id
            ));
            while($activity_detail = $query->fetchObject()){
               $table_name = $activity_detail->activity_table_details;
               $state_query = db_query("SELECT * FROM states_lgd_code");
while($state_result = $state_query->fetchObject()){
          db_set_active($foss_type);
            $query2 = db_query("SELECT COUNT(project_title) as projects_completed_count, state, city,
from_unixtime(actual_completion_date, '%Y') as year_completion
 FROM " . $table_name . " WHERE approval_status = 3 and state not like '' and state not like 0 and city not like ''  and city not like 0 and state=:state and 
 from_unixtime(actual_completion_date, '%Y-%m-%d') between '2019-01-01' and '2024-03-31'
 GROUP BY state,city, year_completion order by state ASC", array(":state" => $state_result->state_name));
               while($book_result = $query2->fetchObject()){
               $book_data[$book_result->state][$state_result->state_lgd_code][$book_result->city][$foss_type . ' ' . $activity_detail->activity_name][] = 
                array(
                  "count" => $book_result->projects_completed_count,
                  "year_of_completion" => $book_result->year_completion,
                  );
               //$state_data[] = array("state_name" =>$book_result->state);
               //$activity_data[$foss_type . ' ' . $activity_detail->activity_name][$book_result->state] = $book_result;
      }
      db_set_active(); 
}
}
         $state_data = $book_data;
         }
        $state_data['fetched at'] .=   time(); 
$book_data  = $state_data;
 drupal_json_output($book_data);

         }
//return $page_output;

}
function fossee_stats_json() {
   $activity = arg(3);
   $year_of_completion = arg(2);
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
      //db_set_active($foss_type);         
if ($foss_detail->foss_name != 'Scilab' || $foss_detail->foss_name != 'R') {  
   $state_query = db_query("SELECT * FROM states_lgd_code");
while($state_result = $state_query->fetchObject()){
   db_set_active($foss_type);
   $query2 = db_query("SELECT COUNT( pe.book ) as book_count, FROM_UNIXTIME(po.completion_date, '%m') as month_of_year, FROM_UNIXTIME(po.completion_date, '%Y') as year_completion, state, city FROM textbook_companion_preference pe LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id WHERE po.proposal_status =3 AND pe.approval_status =1 and from_unixtime(po.completion_date, '%Y') = " . $year_of_completion . "  and state not like '' and state not like 0 and city not like ''  and city not like 0 and state =:state  group by month_of_year, state,city, year_completion order by po.completion_date ASC", array(":state"=> $state_result->state_name));
   while($book_count_data = $query2->fetchObject()){
      //var_dump($book_count_data);die;
      $book_data[$book_count_data->state][$state_result->state_lgd_code][$book_count_data->city][$foss_type][] = array(
         "count" => $book_count_data->book_count,
         "month_of_year" => $book_count_data->month_of_year
      );
      //var_dump($book_data);die;
  }
  db_set_active();
}
 }
 else if ($foss_detail->foss_name == 'Scilab' || $foss_detail->foss_name == 'R') {  
   $state_query = db_query("SELECT * FROM states_lgd_code");
while($state_result = $state_query->fetchObject()){
   db_set_active($foss_type);
   $query3 = db_query("SELECT count(DISTINCT pe.id) as book_count, FROM_UNIXTIME(po.completion_date, '%m') as month_of_year, FROM_UNIXTIME(po.completion_date, '%Y') as year_completion, state, city
      FROM textbook_companion_preference pe
      LEFT JOIN textbook_companion_proposal po ON pe.proposal_id = po.id
      LEFT JOIN textbook_companion_book_main_subcategories tcbm ON pe.id = tcbm.pref_id
      LEFT JOIN list_of_category loc ON tcbm.main_category = loc.category_id
      WHERE po.proposal_status = 3 AND pe.approval_status = 1 AND pe.category>0 and state not like '' and state not like 0 and city not like ''  and city not like 0 and state =:state
      AND pe.id = tcbm.pref_id and from_unixtime(po.completion_date, '%Y') =" . $year_of_completion . " group by month_of_year, state,city, year_completion order by po.completion_date ASC", array(":state"=> $state_result->state_name));
   while($book_count_data = $query3->fetchObject()){
      //var_dump($book_count_data);die;
      $book_data[$book_count_data->state][$state_result->state_lgd_code][$book_count_data->city][$foss_type][] .= array(
         "count" => $book_count_data->book_count,
         "month_of_year" => $book_count_data->month_of_year
      );
      //var_dump($book_data);die;
  }
  //var_dump($book_data);die;

db_set_active();
}
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
            $foss_type = $foss_detail->foss_name;
            $state_query = db_query("SELECT * FROM states_lgd_code");
while($state_result = $state_query->fetchObject()){
      db_set_active($foss_type);         
   $query2 = db_query("SELECT COUNT(id) as lab_count, from_unixtime(approval_date, '%m') as month_of_year, state, city,
 from_unixtime(approval_date, '%m') as month_of_year,
from_unixtime(approval_date, '%Y') as year_completion FROM lab_migration_proposal WHERE approval_status = '3'  and state not like '' and state not like 0 and city not like ''  and city not like 0 and state =:state and
 from_unixtime(approval_date, '%Y') = " . $year_of_completion . "
 GROUP BY month_of_year, state,city, year_completion order by state ASC", array(":state" => $state_result->state_name));
   while($book_count_data = $query2->fetchObject()){
      //var_dump($book_count_data);die;
      $book_data[$book_count_data->state][$state_result->state_lgd_code][$book_count_data->city][$foss_type][] = array(
         "count" => $book_count_data->lab_count,
         "month_of_year" => $book_count_data->month_of_year
      );
      //var_dump($book_data);die;
  }
}
db_set_active();
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
            $query = db_query("SELECT * FROM foss_niche_activites a WHERE a.foss_id=:foss_id and is_active=1", array(
               ":foss_id" => $foss_detail->id
            ));
            while($activity_detail = $query->fetchObject()){
               $table_name = $activity_detail->activity_table_details;
               $state_query = db_query("SELECT * FROM states_lgd_code");
while($state_result = $state_query->fetchObject()){
          db_set_active($foss_type);
            $query2 = db_query("SELECT COUNT(project_title) as projects_completed_count, state, city,
 from_unixtime(actual_completion_date, '%m') as month_of_year,
from_unixtime(actual_completion_date, '%Y') as year_completion
 FROM " . $table_name . " WHERE approval_status = 3 and state not like '' and state not like 0 and city not like ''  and city not like 0 and state=:state and 
 from_unixtime(actual_completion_date, '%Y') = " . $year_of_completion . "
 GROUP BY month_of_year, state,city, year_completion order by state ASC", array(":state" => $state_result->state_name));
               while($book_result = $query2->fetchObject()){
               $book_data[$book_result->state][$state_result->state_lgd_code][$book_result->city][$foss_type . ' ' . $activity_detail->activity_name][] = 
                array(
                  "count" => $book_result->projects_completed_count,
                  "month_of_year" => $book_result->month_of_year,
                  );
               //$state_data[] = array("state_name" =>$book_result->state);
               //$activity_data[$foss_type . ' ' . $activity_detail->activity_name][$book_result->state] = $book_result;
      }
      db_set_active(); 
}
}
         $state_data = $book_data;
         }
        $state_data['fetched at'] .=   time(); 
$book_data  = $state_data;
 drupal_json_output($book_data);
 //exit;
         }


}
